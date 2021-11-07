/*
Given an array of n integers, your task is to calculate the number of subarrays that have at most k distinct values.
Input
The first input line has two integers n and k.
The next line has n integers x1,x2,…,xn: the contents of the array.
Output
Print one integer: the number of subarrays.
Constraints
1≤k≤n≤2⋅10^5
1≤xi≤10^9
Example
Input:
5 2
1 2 3 1 1
Output:
10
SOLUTION
Sliding window
Hash table to put (Distinct value in window xs[i:j+1], count)
Time O(N)
Space O(K)

References
- https://www.codingninjas.com/codestudio/problem-details/subarrays-with-at-most-k-distinct-values_1473804
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<ll> xs(n);
    for (ll i = 0; i < n; i++)
        cin >> xs[i];
    // In a map, default value is zero
    map<ll, ll> cnt;
    // i and j are head and tail of window
    // c is #distinct values in window xs[i:j+1]
    ll i = 0, j = 0, c = 0, res = 0;
    while (i < n)
    {
        // tail is a new value, grow window to the right
        while (j < n && c + (cnt[xs[j]] == 0) <= k)
        {
            if (++cnt[xs[j]] == 1)
                c++;
            j++;
        }
        // Either we have reached the end of the array or,
        // window now has >k distinct values, shrink from the left.
        // Size of window = #valid subarrays ending at j-1
        // res += j - 1 - i + 1;
        res += j - i;
        if (cnt[xs[i]]-- == 1)
            c--;
        i++;
    }
    cout << res;
    return 0;
}