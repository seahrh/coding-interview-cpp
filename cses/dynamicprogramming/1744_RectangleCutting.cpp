/*
Given an a×b rectangle, your task is to cut it into squares.
On each move you can select a rectangle and cut it into two rectangles
in such a way that all side lengths remain integers.
What is the minimum possible number of moves?
Input
The only input line has two integers a and b.
Output
Print one integer: the minimum number of moves.
Constraints
1≤a,b≤500
Example
Input:
3 5
Output:
3
SOLUTION
dp[i][j] = min number of ways to cut ixj rectangle into squares
Base case: if i == j then dp[i][j] = 0
Recurrence: 
Vertical cuts, dp[i][j] = min(dp[i][j], 1 + dp[i][j - tj] + dp[i][tj]);
Horizontal cuts, dp[i][j] = min(dp[i][j], 1 + dp[i - ti][j] + dp[ti][j]);
Time O(AB * (A + B)) = O(A^2B + AB^2)
Space O(AB)
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b)
{
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, INT_MAX));
    for (int i = 1; i < a + 1; i++)
    {
        for (int j = 1; j < b + 1; j++)
        {
            if (i == j)
            {
                dp[i][j] = 0;
                continue;
            }
            // vertical cuts
            for (int k = 1; k < j; k++)
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - k] + dp[i][k]);
            // horizontal cuts
            for (int k = 1; k < i; k++)
                dp[i][j] = min(dp[i][j], 1 + dp[i - k][j] + dp[k][j]);
        }
    }
    return dp[a][b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    cout << solve(a, b);
    return 0;
}