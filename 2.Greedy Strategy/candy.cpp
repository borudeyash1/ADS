/*
Candy Distribution
Distribute Candies such that each kid with a higher score gets more than neighbours
Input : rating[1,0,2]
Output: 5
*/

#include <iostream>
using namespace std;

int main()
{

    int n;
    int candies[n];
    int ratings[n];
    cout << "Enter the number of kids: ";
    cin >> n;
    cout << "Enter the ratings of kids: ";
    for (int i = 0; i < n; i++)
    {
        cin >> ratings[i];
        candies[i] = 1;
    }
    int totalcandies = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && ratings[i] > ratings[i - 1])
        {
            candies[i] += candies[i - 1] + 1;
        }
        else if (i == 0)
        {
            candies[i] = 1;
        }
        totalcandies += candies[i];
    }
    cout << "Total candies: " << totalcandies;
    return 0;
}
