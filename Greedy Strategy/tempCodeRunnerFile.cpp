/*
Implement a problem of activity selection problem with K persons.
Problem Statement: given two arrays S[] and E[] of size N denoting starting and closing time of the shop and an integer value K denoting the number of people, the task is to find out the maximum number of shops they can visit in total if they visit each shop optimally based on the following conditions:
1) A shop can be visited by only one person.
2) A person cannot visit another shop if its timing collide with it

-> 1.input
S[]={1,8,3,2,6}
E[]={5,10,6,5,9}
K=2
Output = 4

-> 2.input
S[]={1,2,3}
E[]={3,4,5}
K=2
Output = 3

*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N; // number of shops
    cout << "Enter Total Shops: ";
    cin >> N;

    int S[N], E[N];              // start and end times
    bool isVisited[N] = {false}; // visited flags
    int K;                       // number of persons
    cout << "Enter Total Persons: ";
    cin >> K;

    // Input start and end times
    for (int i = 0; i < N; ++i)
    {
        cout << i + 1 << " Shop Start Time: ";
        cin >> S[i];
        cout << i + 1 << " Shop End Time: ";
        cin >> E[i];
    }

    // Create index array to sort shops by start time
    int idx[N];
    for (int i = 0; i < N; ++i)
        idx[i] = i;

    // Sort indices based on S[idx[i]]
    sort(idx, idx + N, [&](int a, int b)
         { return S[a] < S[b]; });

    int count = 0;

    // Main logic: simulate each person visiting shops
    for (int i = 0; i < K; ++i)
    {
        int current = S[idx[i % N]]; // start from i-th shop's start time
        for (int j = 0; j < N; ++j)
        {
            int shop = idx[j];
            if (!isVisited[shop] && S[shop] >= current)
            {
                isVisited[shop] = true;
                current = E[shop];
                count++;
            }
        }
    }

    cout << "Total Visited Shops: " << count << endl;

    return 0;
}
