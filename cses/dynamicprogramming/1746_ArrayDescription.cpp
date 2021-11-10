/*
You know that an array has n integers between 1 and m, and the **difference between two adjacent values is at most 1**.
Given a description of the array where some values may be unknown,
your task is to count the number of arrays that match the description.
Input
The first input line has two integers n and m: the array size and the upper bound for each value.
The next line has n integers x1,x2,…,xn: the contents of the array. Value 0 denotes an unknown value.
Output
Print one integer: the number of arrays modulo 10^9+7.
Constraints
1≤n≤10^5
1≤m≤100
0≤xi≤m
Example
Input:
3 5
2 0 2
Output:
3
Explanation: The arrays [2,1,2], [2,2,2] and [2,3,2] match the description.
SOLUTION
Bottom-up DP, fill memo table row-wise.
dp[i][j] = #arrays matching the first i items and ith value == j.
Base case: array has only one item
- If first item is zero, then it matches for all M.

Recurrence: dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]
- Why top 3 cells? The difference between two adjacent values is at most 1.

Answer: sum the last row i.e. all possible ways for all N items and M values
Time O(NM)
Space O(NM)
*/
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int solve(int n, int m, vector<int> ar)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    // Base case
    for (int j = 1; j < m + 1; j++)
        if (ar[0] == 0 || ar[0] == j)
            dp[1][j] = 1;
    // loop starts from 2nd item
    for (int i = 2; i < n + 1; i++)
        for (int j = 1; j < m + 1; j++)
            if (ar[i - 1] == 0 || ar[i - 1] == j)
            {
                (dp[i][j] += dp[i - 1][j - 1] + dp[i - 1][j]) %= mod;
                // Prevent IndexOutOfBounds
                if (j + 1 <= m)
                    (dp[i][j] += dp[i - 1][j + 1]) %= mod;
            }
    int res = 0;
    for (auto v : dp[n])
        (res += v) %= mod;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> ar(n);
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    cout << solve(n, m, ar);
    return 0;
}
