/*
Count the number of ways numbers 1,2,…,n can be divided into two sets of equal sum.
For example, if n=7, there are four solutions:
{1,3,4,6} and {2,5,7}
{1,2,5,6} and {3,4,7}
{1,2,4,7} and {3,5,6}
{1,6,7} and {2,3,4,5}
Input
The only input line contains an integer n.
Output
Print the answer modulo 10^9+7.
Constraints
1<=n<=500
Example
Input:
7
Output:
4
SOLUTION
Run 0-1 knapsack to get the number of ways to reach n(n+1)/4 using subsets of the numbers 1..n-1
Why n-1? Because by considering numbers up to n-1, we always put n in the second set,
and therefore only count each pair of sets once (otherwise we count every pair of sets twice).
dp[i][j] = number of ways to form subset sum j from the first i numbers 
Base case: empty set to make sum 0, dp[i][0] = 1
The rest of the first row, dp[0][j] = 0
Recurrence: dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i]
Either take the ith number or not.
Time O(N^3)
Space O(N^3): memo table
See https://codeforces.com/blog/entry/70018
*/
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int solve(int n)
{
    // triangular number
    int s = n * (n + 1) / 2;
    if (s % 2 == 1)
        return 0;
    s /= 2;
    vector<vector<int>> dp(n, vector<int>(s + 1));
    // Base case
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < s + 1; j++)
        {
            // Already make sum j without ith coin
            dp[i][j] = dp[i - 1][j];
            if (j - i >= 0)
                (dp[i][j] += dp[i - 1][j - i]) %= mod;
        }
    }
    return dp[n - 1][s];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}