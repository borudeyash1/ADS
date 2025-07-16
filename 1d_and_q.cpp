#include<iostream>
using namespace std;

class divide_and_conquer {
    int a[100], n;

public:
    void bins() {
        int mid, l = 0, r, key;
        cout << "Enter count of elements to be inserted: ";
        cin >> n;
        cout << "Enter the elements (sorted): ";
        for (int i = 0; i < n; i++)
            cin >> a[i];
        r = n - 1;
        cout << "Enter the element to be searched: ";
        cin >> key;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (a[mid] == key) {
                cout << "Element found at index: " << mid << endl;
                return;
            } else if (a[mid] < key) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << "Element not found" << endl;
    }


    void start_merge_sort() {
        cout << "Enter count of elements to be sorted: ";
        cin >> n;
        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++)
            cin >> a[i];
        merge_sort(0, n - 1);
        cout << "Sorted array: ";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }

    void merge_sort(int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            merge_sort(low, mid);
            merge_sort(mid + 1, high);
            merge(low, mid, high);
        }
    }

    void merge(int low, int mid, int high) {
        int n1 = mid - low + 1;
        int n2 = high - mid;
        int L[100], R[100]; // size  100 max

        for (int i = 0; i < n1; i++)
            L[i] = a[low + i];
        for (int j = 0; j < n2; j++)
            R[j] = a[mid + 1 + j];

        int i = 0, j = 0, k = low;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                a[k++] = L[i++];
            } else {
                a[k++] = R[j++];
            }
        }

        while (i < n1)
            a[k++] = L[i++];

        while (j < n2)
            a[k++] = R[j++];
    }
};

int main() {
    int choice;
    divide_and_conquer dac;

    while (true) {
        cout << "\nDIVIDE AND CONQUER METHODS\n1. Binary Search\n2. Merge Sort\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                dac.bins();
                break;
            case 2:
                dac.start_merge_sort();
                break;
            case 3:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}