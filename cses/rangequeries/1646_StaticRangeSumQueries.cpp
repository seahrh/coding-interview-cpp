/*
Given an array of n integers, your task is to process q queries of the form: 
what is the sum of values in range [a,b]? 
Input
The first input line has two integers n and q: the number of values and queries.
The second line has n integers x1,x2,…,xn: the array values.
Finally, there are q lines describing the queries.
Each line has two integers a and b: what is the sum of values in range [a,b]?
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
11
2
24
4
SOLUTION
Prefix Sum Array
Time O(N + Q)
Space O(N)
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
    vector<ll> pre(n + 1);
    // pre[0] = 0
    for (ll i = 1; i < n + 1; i++)
    {
        ll x;
        cin >> x;
        pre[i] = x + pre[i - 1];
    }
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        cout << pre[b] - pre[a - 1] << endl;
    }
    return 0;
}