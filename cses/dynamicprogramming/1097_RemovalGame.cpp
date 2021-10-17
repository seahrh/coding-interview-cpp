/*
There is a list of n numbers and two players who move alternately.
On each move, a player removes either the first or last number from the list, and their score increases by that number.
Both players try to maximize their scores.
What is the maximum possible score for the first player when both players play optimally?
Input
The first input line contains an integer n: the size of the list.
The next line has n integers x1,x2,…,xn: the contents of the list.
Output
Print the maximum possible score for the first player.
Constraints
1≤n≤5000
−10^9≤xi≤10^9
Example
Input:
4
4 5 1 3
Output:
8
SOLUTION
The sum of the two players' scores is the sum of the input list.
Player 1 tries to maximize (score1 − score2), while player 2 tries to minimize it.
Bottom-up DP with a twist: fill memo table upwards from last row to first row
dp[i] = difference (score1 - score2) considering the game played only on interval [i, j].
Base case: If there is only one item in the interval (i == j), then the first player must take that item.
dp[i][j] = xs[i]
Recurring relation: dp[i] = max(take_head, take_tail)
Take head, P2 starts first on [i + 1, j], thus xs[i] - dp[i + 1][j]
Take tail, P2 starts first on [i, j - 1], thus xs[j] - dp[i][j - 1]
Final answer is the mean of the total sum and (s1 - s2)
i.e. (s1 + s2 + (s1 - s2)) / 2 = 2s1 / 2 = s1
Time O(N^2)
Space O(N^2)
See https://codeforces.com/blog/entry/70018
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(int n, vector<ll> xs)
{
    vector<vector<ll>> dp(n, vector<ll>(n));
    ll s = 0;
    for (ll x : xs)
    {
        s += x;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                dp[i][j] = xs[i];
                continue;
            }
            ll head = xs[i] - dp[i + 1][j];
            ll tail = xs[j] - dp[i][j - 1];
            dp[i][j] = max(head, tail);
        }
    }
    return (s + dp[0][n - 1]) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> xs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> xs[i];
    }
    cout << solve(n, xs);
    return 0;
}