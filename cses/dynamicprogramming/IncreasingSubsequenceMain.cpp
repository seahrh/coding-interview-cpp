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
dp[i] = **smallest ending value** of an increasing subsequence of length i+1,
using the elements considered so far.
dp is a sorted array, so exploit binary search to find index where item should be inserted.
The final answer is the length of the dp array after considering all elements.
In this task we were asked to find the longest strictly increasing subsequence.
To find the longest increasing subsequence where we allow consecutive equal values, change lower_bound to upper_bound.
See https://codeforces.com/blog/entry/70018
Time O(N lg N): binary search in the loop
Space O(N)
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
            // same as *it = xs[i];
            int j = distance(dp.begin(), it);
            dp[j] = xs[i];
        }
    }
    return dp.size();
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