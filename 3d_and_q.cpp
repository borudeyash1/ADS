/*impleement the problem of smallest number with at least n trailing zeroes in factorial

    The trailing zeroes in a factorial are produced by the factors of 5 and 2, but since there are always more factors of 2 than 5, we only need to count the number of times 5 is a factor in the numbers from 1 to n.
 contains at least n trailing zeroes
 input: n= 1    Output:5
 input: n = 6;  Output:25'
 exmaple:*/


#include <iostream>
using namespace std;

// Function to count the trailing zeroes in factorial of a number
int countTrail(int n){
    int count = 0;
    while (n > 0){
        n /= 5;  //it means we are counting the number of factors of 5 in the numbers from 1 to n
        count+= n; //and adding them to the count
        // This counts how many multiples of 5, 25, 125, etc.are in the numbers from 1 to n
    }
    return count;
}

// Function to find the smallest number such that its factorial contains at least n trailing zeroes
int min(){
    int n;
    int low = 0,high= 5*n;                             // upper bound finding 
    int result = -1;               // Initialize result to -1 to indicate not found

while (low <= high){
int mid =(low+high)/2;                              // Calculate mid point
    int zeroes = countTrail(mid);       // Count the trailing zeroes in mid factorial

    if (zeroes < n){                   // If the count is less than n, we need to search in the higher range
        low = mid + 1;
    } else {                     // If the count is greater than or equal to n, we can potentially update the result
        result = mid;                     
        high = mid - 1;
        }
 }
    return result;
}
int main() {
    int n;
    cout << "Enter the number of trailing zeroes required: ";
    cin >> n;

    int result = min();
    cout << "The smallest number whose factorial has at least "<<n<<"trailing zeroes is: " << result << endl;

    return 0;
}