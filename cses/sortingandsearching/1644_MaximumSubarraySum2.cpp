/*
Given an array of n integers, find the maximum sum of values in a contiguous subarray with length between a and b.
Input
The first input line has three integers n, a and b: the size of the array and the minimum and maximum subarray length.
The second line has n integers x1,x2,…,xn: the array values.
Output
Print one integer: the maximum subarray sum.
Constraints
1≤n≤2⋅10^5
1≤a≤b≤n
−10^9≤xi≤10^9
Example
Input:
8 1 2
-1 3 -2 5 3 -5 2 2
Output:
8
SOLUTION
Prefix sum array: ps[i] = sum of the first i elements
ps[0] = 0 because ps[0] is sum of empty subarray.
Each subarray sum is represented as (ps[j] - ps[i])
where a <= j - i <= b and (j - i) is the size of the subarray.
To maximize ps[j] - ps[i], minimize ps[i].
Pass a sliding window through prefix sum array, 
where (j-b) and (j-a) represent head and tail of window.
**This window contains all possible positions of i.
Use a BST to maintain the min value in the range 
by adding ps[j-a] and removing ps[j-b] in each iteration.
Time O(N lg N)
Space O(N)
References
- https://discuss.codechef.com/t/help-with-maximum-subarray-sum-ii-from-cses/73404
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> xs(n);
    for (int i = 0; i < n; i++)
        cin >> xs[i];
    // prefix sum array
    vector<ll> ps(n + 1);
    for (int i = 1; i < n + 1; i++)
        ps[i] = ps[i - 1] + xs[i - 1];
    multiset<ll> bst;
    ll res = LLONG_MIN;
    for (ll j = a; j < n + 1; j++)
    {
        if (j > b)
            // minus 1 bec it is left of the head of window
            bst.erase(bst.find(ps[j - b - 1]));
        // tail of window
        bst.insert(ps[j - a]);
        // mss = ps[j] - smallest ps[i]
        res = max(res, ps[j] - *bst.begin());
    }
    cout << res;
    return 0;
}