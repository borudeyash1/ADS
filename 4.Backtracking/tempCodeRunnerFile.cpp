#include <iostream>
#include <cmath> // For std::pow
#include <algorithm> // For std::sort

using namespace std;

// Utility function to print a subset (array) of a given size
void print_subset(int subset_arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; ++i) {
        cout << subset_arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

// print all subsets using BitMasking
void findSubsets(int arr[], int n) {
    // Total number of subsets is 2^n
    int total_subsets = 1 << n; // Equivalent to std::pow(2, n)

    cout << "Subsets (includes duplicates due to 'no vector' constraint):" << endl;

    
    for (int mask = 0; mask < total_subsets; ++mask) {
        
        // This temporary array will store the current subset elements
        // The maximum size of any subset is 'n'
        int current_subset[100]; 
        int subset_size = 0;

        // Iterate through each element of the input array
        for (int i = 0; i < n; ++i) {
            // Check if the i-th bit of the mask is set (1)
            // If it is, the i-th element of the input array belongs to the current subset
            if (mask & (1 << i)) {
                
                current_subset[subset_size] = arr[i];
                subset_size++;
            }
        }
        
        
        std::stable_sort(current_subset, current_subset + subset_size);

        // Print the sorted subset
        print_subset(current_subset, subset_size);
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    std::stable_sort(arr, arr + n);

    cout << "Input Array: [";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
    findSubsets(arr, n);

    delete[] arr;
    return 0;
}