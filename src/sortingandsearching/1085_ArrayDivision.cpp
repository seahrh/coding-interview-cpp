/*
You are given an array containing n positive integers.
Your task is to divide the array into k subarrays so that the maximum sum in a subarray is as small as possible.
Input
The first input line contains two integers n and k: the size of the array and the number of subarrays in the division.
The next line contains n integers x1,x2,…,xn: the contents of the array.
Output
Print one integer: the maximum sum in a subarray in the optimal division.
Constraints
1≤n≤2⋅10^5
1≤k≤n
1≤xi≤10^9
Example
Input:
5 3
2 4 7 3 5
Output:
8
Explanation: An optimal division is [2,4],[7],[3,5] where the sums of the subarrays are 6,7,8.
The largest sum is the last sum 8.
SOLUTION
Binary search on the range of `max_sum` between `lo` and `hi`.
Smallest subarray has length 1, so smallest sum `lo` is the max element.
Largest subarray is the entire array, so largest sum `hi` is the sum of the array.
The answer is `mid` the maximal subarray sum.
If #subarrays is greater than k (subarrays are too short), increase max_sum.
If #subarrays is less than or equals k (subarrays are too long), decrease max_sum.
Time O(N lg NX)
Space O(1)
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll n, ll k, vector<ll> xs)
{
    ll lo = xs[0], hi = 0;
    for (ll x : xs)
    {
        lo = max(lo, x);
        hi += x;
    }
    ll res = hi;
    while (lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2;
        // j is the number of subarrays that have sum <= mid
        ll j = 0;
        // sum of the current subarray
        ll sm = 0;
        for (ll x : xs)
        {
            sm += x;
            // increment count if max_sum `mid` is exceeded!
            if (sm > mid)
            {
                if (++j > k)
                    break;
                // new subarray with x as 1st item
                sm = x;
            }
        }
        // add the last subarray!
        if (sm > 0)
            j++;
        // try a smaller max_sum
        if (j <= k)
        {
            res = mid;
            hi = mid - 1;
            continue;
        }
        lo = mid + 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<ll> xs(n);
    for (int i = 0; i < n; i++)
        cin >> xs[i];
    cout << solve(n, k, xs);
    return 0;
}
