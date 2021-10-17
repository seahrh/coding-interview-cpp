/*
You are given a playlist of a radio station since its establishment. The playlist has a total of n songs.
What is the longest sequence of successive songs where each song is unique?
Input
The first input line contains an integer n: the number of songs.
The next line has n integers k1,k2,…,kn: the id number of each song.
Output
Print the length of the longest sequence of unique songs.
Constraints
1≤n≤2⋅10^5
1≤ki≤10^9
Example
Input:
8
1 2 1 3 2 7 4 2
Output:
5
SOLUTION
Sliding window: grow the window to the right when new item is found.
Shrink window from the left until the "first" duplicate is no longer in the window.
Time O(N)
Space O(N)
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> ks)
{
    int i = 0, j = 0, res = 0;
    set<int> ids;
    while (j < n)
    {
        if (ids.find(ks[j]) == ids.end())
        {
            ids.insert(ks[j]);
            j++;
            res = max(res, static_cast<int>(ids.size()));
        }
        else
        {
            ids.erase(ks[i]);
            i++;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> ks(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ks[i];
    }
    cout << solve(n, ks);
    return 0;
}
