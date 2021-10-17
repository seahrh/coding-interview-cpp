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
Traverse array from left to right. CURRENT_SUM is the sum of elements from first item to current item.
If there exists a prefix sum equals (CURRENT_SUM - TARGET),
then add the number of subarrays containing the prefix sum to the result.
Time O(N)
Space O(N)
See https://www.geeksforgeeks.org/find-subarray-with-given-sum-in-array-of-integers/
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(int n, ll x, vector<ll> ar)
{
    ll res = 0, curr = 0, ps;
    // Map prefix sum to its count of subarrays
    map<ll, ll> prefix_sums;
    for (int i = 0; i < n; i++)
    {
        curr += ar[i];
        if (curr == x)
        {
            res++;
        }
        ps = curr - x;
        auto kv = prefix_sums.find(ps);
        if (kv != prefix_sums.end())
        {
            res += kv->second;
        }
        kv = prefix_sums.find(curr);
        if (kv == prefix_sums.end())
        {
            prefix_sums.insert({{curr, 1}});
        }
        else
        {
            kv->second += 1;
        }
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
    {
        cin >> ar[i];
    }
    cout << solve(n, x, ar);
    return 0;
}
