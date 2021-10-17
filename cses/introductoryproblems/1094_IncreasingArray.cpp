/*
You are given an array of n integers.
Modify the array so that it is increasing, i.e., every element is at least as large as the previous element.
On each turn, you may increase the value of any element by one. What is the minimum number of turns required?
Input
The first input line contains an integer n: the size of the array.
Then, the second line contains n integers x1,x2,…,xn: the contents of the array.
Output
Print the minimum number of turns.
Constraints
1≤n≤2⋅10^5
1≤xi≤10^9
Example
Input:
5
3 2 5 1 7
Output:
5
SOLUTION
Time O(N)
Space O(1)
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll n, vector<ll> xs)
{
    ll res = 0;
    ll prev = xs[0];
    for (ll i = 1; i < n; i++)
    {
        while (xs[i] < prev)
        {
            xs[i]++;
            res++;
        }
        prev = xs[i];
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> xs(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> xs[i];
    }
    cout << solve(n, xs);
    return 0;
}
