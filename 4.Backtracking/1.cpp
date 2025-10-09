#include <iostream>
#include <algorithm> 
#include <set>       
#include <string>    

using namespace std;


string subset_to_string(int subset_arr[], int size) {
    string s = "";
    if (size == 0) {
        return "NULL"; // Unique identifier for the empty set
    }
    for (int i = 0; i < size; ++i) {
        // Use a delimiter (e.g., '#') to distinguish elements in the string
        s += to_string(subset_arr[i]) + "#";
    }
    return s;
}


void findUniqueSubsets(int arr[], int n) {
    int total_subsets = 1 << n;
    
    // Use a set of strings to automatically store only unique subsets
    set<string> unique_subsets_keys;

    for (int mask = 0; mask < total_subsets; ++mask) {
        // Temporary C-style array to hold the current subset
        // Maximum size is 'n', assuming n < 100 for simplicity
        int current_subset[100]; 
        int subset_size = 0;

        // 1. Generate the subset based on the mask
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                current_subset[subset_size] = arr[i];
                subset_size++;
            }
        }
        
        // 2. Sort the individual subset
        // Sorting is crucial so that subsets like [1, 2] and [2, 1] 
        // have the same string key after conversion.
        std::sort(current_subset, current_subset + subset_size);
        
        // 3. Convert the sorted subset array to a unique string key and insert into the set
        string subset_key = subset_to_string(current_subset, subset_size);
        unique_subsets_keys.insert(subset_key);
    }

    // 4. Print the unique subsets from the set
    cout << "Unique Subsets:" << endl;
    
    // We'll store the final subsets in a dynamic array of strings for final output order
    // But since order is not strictly required, we can print directly.
    for (const string& key : unique_subsets_keys) {
        if (key == "NULL") {
            cout << "[], "; // Print the empty set
            continue;
        }

        cout << "[";
        size_t start = 0;
        size_t end = key.find('#');
        bool first = true;
        
        // Parse the string key to print the elements with formatting
        while (end != string::npos) {
            if (!first) {
                cout << ", ";
            }
            cout << key.substr(start, end - start);
            start = end + 1;
            end = key.find('#', start);
            first = false;
        }
        cout << "]";
        
        // Check if this is the last element to avoid trailing comma or newline
        if (*unique_subsets_keys.rbegin() != key) {
             cout << ", ";
        }
    }
    
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    if (!(cin >> n) || n <= 0 || n > 100) {
        cout << "Invalid size." << endl;
        return 1;
    }

    int* arr = new int[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        if (!(cin >> arr[i])) {
            cout << "Invalid input element." << endl;
            delete[] arr;
            return 1;
        }
    }
    std::sort(arr, arr + n);

    cout << "Input Array: [";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << (i < n - 1 ? " " : "");
    }
    cout << "]" << endl;
    
    findUniqueSubsets(arr, n);

    delete[] arr;
    return 0;
}