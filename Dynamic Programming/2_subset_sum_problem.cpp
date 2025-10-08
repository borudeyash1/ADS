/*Subset Sum Problem

Given an array arr[] of non-negative integers and a value sum, the task is to check if there is a subset of the given array whose sum is equal to the given sum. 

Examples: 

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: True
Explanation: There is a subset (4, 5) with sum 9.

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
Output: False
Explanation: There is no subset that add up to 30.*/
#include <iostream>

using namespace std;

bool isSubsetSumRec(int arr[], int n, int sum) {
  
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    // If last element is greater than sum,
    // then ignore it
    if (arr[n - 1] > sum)
        return isSubsetSumRec(arr, n - 1, sum);

    // Check if sum can be obtained by including
    // or excluding the last element
    return isSubsetSumRec(arr, n - 1, sum)
        || isSubsetSumRec(arr, n - 1, sum - arr[n - 1]);
}

bool isSubsetSum(int arr[], int size, int sum) {
    return isSubsetSumRec(arr, size, sum);
}

int main() {
  
    int arr[] = {3, 34, 4, 12, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = 9;

    if (isSubsetSum(arr, size, sum))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
