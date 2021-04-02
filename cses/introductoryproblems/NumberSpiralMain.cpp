/*
A number spiral is an infinite grid whose upper-left square has number 1.
Here are the first five layers of the spiral:

1, 2, 9, 10, 25
4, 3, 8, 11, 24
5, 6, 7, 12, 23
16, 15, 14, 13, 22
17, 18, 19, 20, 21

Your task is to find out the number in row y and column x.
Input
The first input line contains an integer t: the number of tests.
After this, there are t lines, each containing integers y and x.
Output
For each test, print the number in row y and column x.
Constraints
1≤t≤105
1≤y,x≤109
Example
Input:
3
2 3
1 1
4 2
Output:
8
1
15
SOLUTION
Diagonal cells (1,1), (2, 2), (3, 3)... are given by z * z - (z - 1).
After getting the diagonal value, then traverse left or top to find the target cell.
Depending on whether x or y is even or odd, the sequence is either monotonically increasing or decreasing.
Time O(1)
Space O(1)
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll y, ll x)
{
    ll z = max(y, x);
    ll res = z * z - (z - 1);
    // Going left of the diagonal
    if (x < y)
    {
        if (y % 2 == 0)
        {
            res += y - x;
        }
        else
        {
            res -= y - x;
        }
    }
    // Going top of the diagonal
    else
    {
        if (x % 2 == 0)
        {
            res -= x - y;
        }
        else
        {
            res += x - y;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, y, x;
    cin >> t;
    while (t--)
    {
        cin >> y >> x;
        cout << solve(y, x) << "\n";
    }
    return 0;
}