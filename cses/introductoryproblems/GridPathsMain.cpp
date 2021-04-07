/*
There are 88418 paths in a 7×7 grid from the upper-left square to the lower-left square.
Each path corresponds to a 48-character description consisting of characters D (down), U (up), L (left) and R (right).
For example, the path corresponds to the description DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD.
You are given a description of a path which may also contain characters ? (any direction).
Your task is to calculate the number of paths that match the description.
Input
The only input line has a 48-character string of characters ?, D, U, L and R.
Output
Print one integer: the total number of paths.
Example
Input:
??????R??????U??????????????????????????LD????D?
Output:
201
SOLUTION
*/
#include <bits/stdc++.h>
using namespace std;

void _solve(int i, int j, vector<vector<bool>> &visited, string &s, int a, int &result)
{
    if (i == 6 && j == 6 && a == 48)
    {
        ++result;
        return;
    }
    visited[i][j] = true;
    if (s[a] == '?' || s[a] == 'L')
    {
        if (j - 1 >= 0 && !visited[i][j - 1])
        {
            _solve(i, j - 1, visited, s, a + 1, result);
        }
    }
    if (s[a] == '?' || s[a] == 'R')
    {
        if (j + 1 < 7 && !visited[i][j + 1])
        {
            _solve(i, j + 1, visited, s, a + 1, result);
        }
    }
    if (s[a] == '?' || s[a] == 'U')
    {
        if (i - 1 >= 0 && !visited[i - 1][j])
        {
            _solve(i - 1, j, visited, s, a + 1, result);
        }
    }
    if (s[a] == '?' || s[a] == 'D')
    {
        if (i + 1 < 7 && !visited[i + 1][j])
        {
            _solve(i + 1, j, visited, s, a + 1, result);
        }
    }
}

int solve(string s)
{
    int res = 0;
    vector<vector<bool>> visited(7, vector<bool>(7));
    _solve(0, 0, visited, s, 0, res);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    cout << solve(s);
    return 0;
}
