/*
Given an array of n positive integers, your task is to count the number of subarrays having sum x.
Input
The first input line has two integers n and x: the size of the array and the target sum x.
The next line has n integers a1,a2,…,an: the contents of the array.
Output
Print one integer: the required number of subarrays.
Constraints
1≤n≤2⋅10^5
1≤x,ai≤10^9
Example
Input:
5 7
2 4 1 2 7
Output:
3
SOLUTION
Sliding window
Time O(N)
Space O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int n, int x, vector<int> ar)
{
    int res = 0, i = 0, j = 0, _sum = 0;
    // handle the last subarray! (shrink from the left)
    while (j < n || _sum >= x)
    {
        if (_sum < x)
        {
            _sum += ar[j];
            j++;
            continue;
        }
        if (_sum == x)
        {
            res++;
        }
        _sum -= ar[i];
        i++;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> ar(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    cout << solve(n, x, ar);
    return 0;
}
