/*
Implement a problem of move all zeroes to end of
array.
Statement: Given an array of random numbers, Push all the zero’s
of a given array to the end of the array. For example, if the given
arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 9,
8, 4, 2, 7, 6, 0, 0, 0, 0}. The order of all other elements should be
same.
Input :  arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
Output : arr[] = {1, 2, 4, 3, 5, 0, 0, 0};
use least time compelexity
use merge sort to find the zeros and send them  to new array at the end and rest non sero elements at the front
using divide and conquer
*/
#include <iostream>
using namespace std;    
int main() {
int arr[] = {1,2,0,4,3,0,5,0};
int n = sizeof(arr)/sizeof(arr[0]);
    
    // Count of non-zero elements
    int count = 0;

    // Traverse the array and move non-zero elements to the front
    for (int i = 0;i < n;i++){
        if (arr[i]!=0) {
            arr[count++] = arr[i];
        }
    }

    // Fill the remaining positions with zeroes
    while (count < n){
        arr[count++] = 0;
    }

    cout << "Array after moving zeroes to the end: ";
    for(int i = 0;i < n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
