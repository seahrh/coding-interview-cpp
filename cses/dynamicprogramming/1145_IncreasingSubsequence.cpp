/*
You are given an array containing n integers.
Your task is to determine the longest increasing subsequence in the array
i.e., the longest subsequence where every element is larger than the previous one.
A subsequence is a sequence that can be derived from the array by deleting some elements
without changing the order of the remaining elements.
Input
The first line contains an integer n: the size of the array.
After this there are n integers x1,x2,…,xn: the contents of the array.
Output
Print the length of the longest increasing subsequence.
Constraints
1≤n≤2⋅10^5
1≤xi≤10^9
Example
Input:
8
7 3 5 3 6 2 9 8
Output:
4
SOLUTION
dp[i] = smallest ending value (tail) of an increasing subsequence of length i+1,
For each item x in the array, do one of the following:
(1) if x is larger than all tails, append it, increase the size by 1
(2) if dp[i-1] < x <= dp[i], update dp[i].
Find index i with binary search on dp array (sorted).
Final answer is the length of dp array.

In this task we were asked to find the longest strictly increasing subsequence.
To find the longest increasing subsequence where we allow consecutive equal values,
change lower_bound to upper_bound.

Time O(N lg N): binary search in the loop
Space O(N)

References
- https://codeforces.com/blog/entry/70018
- https://leetcode.com/problems/longest-increasing-subsequence/solutions/74824/JavaPython-Binary-search-O(nlogn)-time-with-explanation/
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> xs)
{
    vector<int> dp;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(dp.begin(), dp.end(), xs[i]);
        if (it == dp.end())
        {
            dp.push_back(xs[i]);
        }
        else
        {
            int j = distance(dp.begin(), it);
            dp[j] = xs[i];
        }
    }
    return (int)dp.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> xs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> xs[i];
    }
    cout << solve(n, xs);
    return 0;
}