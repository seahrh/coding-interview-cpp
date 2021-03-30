/*
You are given all numbers between 1,2,…,n except one. Your task is to find the missing number.
Input
The first input line contains an integer n.
The second line contains n−1 numbers. Each number is distinct and between 1 and n (inclusive).
Output
Print the missing number.
Constraints
2≤n≤2⋅10^5
Example
Input:
5
2 3 1 5
Output:
4
SOLUTION
Missing number = Expected sum - Actual sum
Expected sum is the Triangle Number given by N(N + 1) / 2
Time O(N)
Space O(1)
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll n, vector<ll> ar)
{
    ll s = 0;
    for (ll a : ar)
    {
        s += a;
    }
    return n * (n + 1) / 2 - s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> ar(n - 1);
    for (ll i = 0; i < n - 1; i++)
    {
        cin >> ar[i];
    }
    cout << solve(n, ar);
    return 0;
}
