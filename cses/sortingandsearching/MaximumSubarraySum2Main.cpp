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
Let p[i] denote the sum of the first i elements. Each subarray sum can be represented as a p[j] - p[i].
The question says to maximise it over all values i,j such that a <= j - i <= b,
since j - i is the number of elements in the subarray.
Iterate j from a to n. We want to maximize p[j] - p[i], therefore we want to minimize p[i].
i can be in the range from (j - a) to (j - b).
Since we need to add and remove only one value, use a multiset to maintain the min value
in the range by adding p[j - a] and removing p[j - b] in each iteration.
Time O(N)
Space O(N)
See https://discuss.codechef.com/t/help-with-maximum-subarray-sum-ii-from-cses/73404
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(int n, int a, int b, vector<ll> xs)
{
    // length is n+1 because first item represents empty subarray!
    vector<ll> ps(n + 1);
    ps[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        ps[i] = ps[i - 1] + xs[i - 1];
    }
    multiset<ll> curr;
    ll res = LLONG_MIN;
    for (int j = a; j <= n; j++)
    {
        if (j > b)
        {
            // minus 1 because it is left of the head of the subarray
            curr.erase(curr.find(ps[j - b - 1]));
        }
        curr.insert(ps[j - a]);
        res = max(res, ps[j] - *curr.begin());
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> xs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> xs[i];
    }
    cout << solve(n, a, b, xs);
    return 0;
}