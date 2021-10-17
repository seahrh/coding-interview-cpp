/*
Given an array of n integers, your task is to process q queries of the form:
what is the minimum value in range [a,b]?
Input
The first input line has two integers n and q: the number of values and queries.
The second line has n integers x1,x2,…,xn: the array values.
Finally, there are q lines describing the queries.
Each line has two integers a and b: what is the minimum value in range [a,b]?
Output
Print the result of each query.
Constraints
1≤n,q≤2⋅10^5
1≤xi≤10^9
1≤a≤b≤n
Example
Input:
8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3
Output:
2
1
1
4
SOLUTION
Sparse RMQ table good for MIN, MAX, GCD (when you don't care about overlapping intervals).
Time O(N lg N)
Space O(N lg N)
Query time O(Q)

References
- https://www.youtube.com/watch?v=0jWeUdxrGm4
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    ll max_k = (ll)log2(n) + 1;
    vector<vector<ll>> dp(max_k, vector<ll>(n));
    // Base case: interval length=1 (2^0)
    for (ll i = 0; i < n; i++)
    {
        cin >> dp[0][i];
    }
    // fill sparse table row by row
    for (ll k = 1; k < max_k; k++)
    {
        ll length = 1 << k;  // 2^k
        for (ll i = 0; i < n - length + 1; i++)
        {
            dp[k][i] = min(dp[k - 1][i], dp[k - 1][i + length / 2]);
        }
    }
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        // query expression (a, b) is one-indexed
        a--, b--;
        ll k = (ll)log2(b - a + 1);
        ll length = 1 << k;
        ll res = min(dp[k][a], dp[k][b - length + 1]);
        cout << res << endl;
    }
    return 0;
}
