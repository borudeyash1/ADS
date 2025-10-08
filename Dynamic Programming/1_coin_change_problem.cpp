/*You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1*/



#include <iostream>

using namespace std;

// Returns the count of ways we can
// sum coins[0...n-1] coins to get sum "sum"
int countRecur(int n, int sum, int coins[]) {
  
    // If sum is 0 then there is 1 solution
    // (do not include any coin)
    if (sum == 0) return 1;

    // 0 ways in the following two cases
    if (sum < 0 || n == 0) return 0;

    // count is sum of solutions (i)
    
    return countRecur(n, sum - coins[n - 1], coins) + 
            countRecur(n - 1, sum, coins);
}

int count(int n, int sum, int coins[]) {
    return countRecur(n, sum, coins);
}

int main() {
    int n = 3;
    int sum = 5;
    int coins[] = {1, 2, 3};
    cout << "Number of ways to sum up to " << sum << " using coins {";
    for(int i = 0; i < n; i++) {
        cout << coins[i] << " ";
    }
    cout << "}: " << count(n, sum, coins) << endl;
    return 0;
}

