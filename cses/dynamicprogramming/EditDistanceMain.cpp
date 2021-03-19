/*
The edit distance between two strings is the minimum number of operations required to transform one string into the other.
The allowed operations are:
Add one character to the string.
Remove one character from the string.
Replace one character in the string.
For example, the edit distance between LOVE and MOVIE is 2, because you can first replace L with M, and then add I.
Your task is to calculate the edit distance between two strings.
Input
The first input line has a string that contains n characters between A–Z.
The second input line has a string that contains m characters between A–Z.
Output
Print one integer: the edit distance between the strings.
Constraints
1≤n,m≤5000
Example
Input:
LOVE
MOVIE
Output:
2
SOLUTION
dp[i][j] = min number of moves to change a[:i+1] to b[:j+1]
Base case: dp[0][0] = 0;

*/
#include <bits/stdc++.h>
using namespace std;

int solve(string a, string b)
{
    int na = (int)a.size();
    int nb = (int)b.size();
    vector<vector<int>> dp(na+1, vector<int>(nb+1,5000));
    dp[0][0] = 0;
    for (int i = 0; i <= na; i++) {
        for (int j = 0; j <= nb; j++) {
            // Delete char from a[:i+1], take value from top cell
            if (i - 1 >= 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            }
            // Add char to a[:i+1], take value from left cell (growing to the right)
            if (j - 1 >= 0) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
            if (i - 1 >= 0 && j - 1 >= 0) {
                int tl = dp[i - 1][j - 1];
                // Replace char
                if (a.at(i - 1) != b.at(j - 1)) {
                    tl += 1;
                }
                dp[i][j] = min(dp[i][j], tl);
            }
        }
    }
    return dp[na][nb];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    cout << solve(a, b);
    return 0;
}