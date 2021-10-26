/*
You have n coins with positive integer values. 
What is the smallest sum you cannot create using a subset of the coins?
Input
The first input line has an integer n: the number of coins.
The second line has n integers x1,x2,…,xn: the value of each coin.
Output
Print one integer: the smallest coin sum.
Constraints
1≤n≤2⋅10^5
1≤xi≤10^9
Example
Input:
5
2 9 1 2 7
Output:
6
SOLUTION
dp[i] = smallest sum that cannot be created using the first i coins
Base case: dp[0] = 1
Recurrence: dp[i] = dp[i-1] + xs[i-1]
Time O(N lg N): sort coins
Space O(N)
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> xs(n);
    for (ll i = 0; i < n; i++)
        cin >> xs[i];
    sort(xs.begin(), xs.end());
    vector<ll> dp(n + 1);
    dp[0] = 1;
    for (ll i = 1; i < n + 1; i++)
    {
        // if ith coin is larger, then dp[i-1] is the answer
        if (dp[i - 1] < xs[i - 1])
        {
            cout << dp[i - 1];
            return 0;
        }
        dp[i] = dp[i - 1] + xs[i - 1];
    }
    cout << dp[n];
    return 0;
}
