/*
Consider a money system consisting of n coins. Each coin has a positive integer value.
Your task is to calculate the number of distinct **ordered** ways you can produce a money sum x using the available coins.
For example, if the coins are {2,3,5} and the desired sum is 9, there are 3 ways:
2+2+5
3+3+3
2+2+2+3
Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c1,c2,…,cn: the value of each coin.
Output
Print one integer: the number of ways modulo 10^9+7.
Constraints
1≤n≤100
1≤x≤10^6
1≤ci≤10^6
Example
Input:
3 9
2 3 5
Output:
3
SOLUTION
Bottom up DP: Memoization table has shape (#coins, target). Fill table row by row.
dp[i][x] = number of ways to pick coins with sum x, using the first i coins (exploit requirement for sorted order).
Time O(NX)
Space O(NX)
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int n, int x, vector<int> cs)
{
    const int mod = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    // base case: empty set of coins with target zero
    // If ith coin reduces current target to zero, then add 1.
    dp[0][0] = 1;
    int lo;
    // Prevent IndexOutOfBounds for (i - 1)
    for (int i = 1; i <= n; i++)
    {
        // j must start from 0 so 1st column can carry over values from the top 
        for (int j = 0; j <= x; j++)
        {
            // did not take ith coin (cell above)
            dp[i][j] = dp[i - 1][j];
            // consider ith coin, i starts from 1 so (i - 1) is the ith coin!
            lo = j - cs[i - 1];
            if (lo >= 0)
            {
                (dp[i][j] += dp[i][lo]) %= mod;
            }
        }
    }
    return dp[n][x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> cs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cs[i];
    }
    cout << solve(n, x, cs);
    return 0;
}
