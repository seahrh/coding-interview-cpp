/*
You have two coin piles containing a and b coins.
On each move, you can either remove one coin from the left pile and two coins from the right pile,
or two coins from the left pile and one coin from the right pile.
Your task is to efficiently find out if you can empty both the piles.
Input
The first input line has an integer t: the number of tests.
After this, there are t lines, each of which has two integers a and b: the numbers of coins in the piles.
Output
For each test, print "YES" if you can empty the piles and "NO" otherwise.
Constraints
1≤t≤10^5
0≤a,b≤10^9
Example
Input:
3
2 1
2 2
3 3
Output:
YES
NO
YES
SOLUTION
Each move takes a total of 3 from both piles, so apply modulus.
The smaller pile must not be less than half of the larger pile, else the smaller pile will "dry up" first.
Time O(1)
Space O(1)
*/
#include <bits/stdc++.h>
using namespace std;

bool solve(int a, int b)
{
    return (a + b) % 3 == 0 && min(a, b) * 2 >= max(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, a, b;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;
        if (solve(a, b))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
