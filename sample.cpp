// Find the number of zeros in an array of 1s and 0s, which has all 1s first and 0s followed.


#include <iostream>
using namespace std;

int countZeros(const int arr[], int size) {
    int low = 0, high = size - 1;
    int firstZeroIndex = size;  // Default: no zero found

    while (low <= high) {
        int mid = low + (high - low) / 2;         // Calculate mid index avoiding overflow (low + high) / 2 can overflow when low and high are large values.
        if (arr[mid] == 0) {
            firstZeroIndex = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return size - firstZeroIndex;
}

int main() {
    int arr[] = {1, 1, 1, 0, 0, 0, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Number of zeros: " << countZeros(arr, size) << endl;

    return 0;
}
// The function uses a binary search to find the first zero, and then returns the number of zeros, which is
// the difference between the size of the array and the index of the first zero.

