/*
Given an array of n integers, your task is to count the number of subarrays having sum x.
Input
The first input line has two integers n and x: the size of the array and the target sum x.
The next line has n integers a1,a2,…,an: the contents of the array.
Output
Print one integer: the required number of subarrays.
Constraints
1≤n≤2⋅10^5
−10^9≤x,ai≤10^9
Example
Input:
5 7
2 -1 3 5 -2
Output:
2
SOLUTION
Challenge is to handle negative numbers.
Traverse array from left to right. CURRENT_SUM is the sum of elements from first item to current item.
Remove a prefix R from current sum C to get subarray with sum X.
C - R = X
R = C - X
If there exists a prefix sum R equals (C - X),
then add the number of subarrays containing the prefix sum to the result.
Time O(N)
Space O(N)
References
- https://usaco.guide/problems/cses-1661-subarray-sums-ii/solution
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(int n, ll x, vector<ll> ar)
{
    ll res = 0, pre = 0;
    // Map prefix sum to its count of subarrays
    map<ll, ll> m;
    for (int i = 0; i < n; i++)
    {
        pre += ar[i];
        if (pre == x)
            res++;
        ll rem = pre - x;
        auto it = m.find(rem);
        if (it != m.end())
            res += it->second;
        it = m.find(pre);
        if (it == m.end())
            m.insert({{pre, 1}});
        else
            it->second += 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    cout << solve(n, x, ar);
    return 0;
}
