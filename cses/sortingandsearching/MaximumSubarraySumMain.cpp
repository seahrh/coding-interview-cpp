/*
Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.
Input
The first input line has an integer n: the size of the array.
The second line has n integers x1,x2,…,xn: the array values.
Output
Print one integer: the maximum subarray sum.
Constraints
1≤n≤2⋅10^5
−10^9≤xi≤10^9
Example
Input:
8
-1 3 -2 5 3 -5 2 2
Output:
9
SOLUTION
If sum drops below zero, that subsequence will not contribute to the maximal subarray
since max is reduced by adding the negative sum.
If the array contains all negative numbers, sum is reset for each element,
effectively picking the smallest negative number.
Time O(N)
Space O(1)
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(int n, vector<int> ar)
{
    // cannot init sum as zero because input has negative numbers!
    // cannot init sum as first element because it can be a negative number!
    ll res = LLONG_MIN, curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr += ar[i];
        res = max(res, curr);
        curr = max(curr, 0LL);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    cout << solve(n, ar);
    return 0;
}
