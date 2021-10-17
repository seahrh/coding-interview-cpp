/*
There are n sticks with some lengths. Your task is to modify the sticks so that each stick has the same length.
You can either lengthen and shorten each stick.
Both operations cost x where x is the difference between the new and original length.
What is the minimum total cost?
Input
The first input line contains an integer n: the number of sticks.
Then there are n integers: p1,p2,…,pn: the lengths of the sticks.
Output
Print one integer: the minimum total cost.
Constraints
1≤n≤2⋅10^5
1≤pi≤10^9
Example
Input:
5
2 3 1 5 2
Output:
5
SOLUTION
Sort the array, use the median to divide the array into two equal-sized partitions.
Time O(N lg N)
Space O(1)
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(int n, vector<int> ps)
{
    ll res = 0;
    sort(ps.begin(), ps.end());
    int mid = n / 2;
    int median = ps[mid];
    for (int i = 0; i < n; i++)
    {
        res += abs(median - ps[i]);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> ps(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ps[i];
    }
    cout << solve(n, ps);
    return 0;
}
