/*
You are given a list of n integers, and your task is to calculate the number of distinct values in the list.
Input
The first input line has an integer n: the number of values.
The second line has n integers x1,x2,…,xn.
Output
Print one integers: the number of distinct values.
Constraints
1 <= n <= 2·10^5
1 <= xi <= 10^9
Example
Input:
5
2 3 2 2 3
Output:
2
See https://cses.fi/problemset/task/1621
SOLUTION
Sort the array in-place, then increment count when a different value is seen.
Time O(N lg N)
Space O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> xs)
{
    sort(xs.begin(), xs.end());
    int res = 1;
    for (int i = 1; i < n; i++)
        if (xs[i] != xs[i - 1])
            res++;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> xs(n);
    for (int i = 0; i < n; i++)
        cin >> xs[i];
    cout << solve(n, xs);
    return 0;
}