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
Base case: always possible to make sum zero
dp[0] = 1
Time O(N)
Space O(N): memo array
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, i, j;
    cin >> n;
    vector<ll> dp(n + 1);
    dp[0] = 1;
    for (i = 1; i < n + 1; i++)
    {
        for (j = 1; j <= 6; j++)
            // Prevent ArrayIndexOutOfBounds
            if (i - j >= 0)
                (dp[i] += dp[i - j]) %= mod;
    }
    cout << dp[n];
    return 0;
}
