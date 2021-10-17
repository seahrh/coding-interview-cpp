/*
Your task is to count the number of ways to construct sum n by throwing a dice one or more times.
Each throw produces an outcome between 1 and 6.
For example, if n=3, there are 4 ways:
1+1+1
1+2
2+1
3
Input
The only input line has an integer n.
Output
Print the number of ways modulo 10^9+7.
Constraints
1≤n≤10^6
Example
Input:
3
Output:
4
SOLUTION
Bottom up DP: adding a die roll to previous entries
f[x] = f[x-1] + f[x-2] + f[x-3] + f[x-4] + f[x-5] + f[x-6]
Time O(N)
Space O(N): memo array
*/
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int solve(int n)
{
    vector<int> dp(n + 1, 0);
    // required to initialize f(1) through f(6); single die roll
    dp[0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            // Prevent ArrayIndexOutOfBounds
            if (i - j >= 0)
            {
                dp[i] += dp[i - j];
                dp[i] %= mod;
            }
        }
    }
    return dp[n];
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
