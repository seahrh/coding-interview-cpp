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
1=n,m=5000
Example
Input:
LOVE
MOVIE
Output:
2
SOLUTION
dp[i][j] = min number of moves to change a[:i+1] to b[:j+1]
Base case: both strings are empty, or 1 string has length 1
Recurrence:
- Delete char, dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
  Moving up (e.g. delete chars one by one from non-empty a to get empty string b)
- Add char, dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
  Moving right (e.g. add chars to empty string a to get b)
- Both chars are equal, dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
- Replace char, dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
Time O(NM)
Space O(NM)
*/
#include <bits/stdc++.h>
using namespace std;

int solve(string a, string b)
{
    int na = (int)a.size();
    int nb = (int)b.size();
    vector<vector<int>> dp(na + 1, vector<int>(nb + 1, 5000));
    // Base case
    dp[0][0] = 0;
    for (int i = 1; i < na + 1; i++)
        dp[i][0] = i;
    for (int i = 1; i < nb + 1; i++)
        dp[0][i] = i;
    for (int i = 1; i < na + 1; i++)
    {
        for (int j = 1; j < nb + 1; j++)
        {
            // minus 1 because dp[0] means empty string!
            int r = (a[i - 1] != b[j - 1]);
            // min([add, delete, replace])
            dp[i][j] = min({dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1] + r});
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