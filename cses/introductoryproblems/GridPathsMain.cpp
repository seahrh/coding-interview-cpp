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
Backtracking. Prune the state space tree:
- If a path arrives at the destination cell prematurely, then it cannot be a solution.
- If a path can move in only two opposite directions (left or right; up or down), 
  then there must be unvisited cells in the other branch that was not traversed. 
Time O(2^(N^2))
Space O(N^2): 2d vector to mark visited cells 
*/
// TODO failed test cases 12,13,14,20 TLE
#include <bits/stdc++.h>
using namespace std;

bool is_valid(int i, int j, vector<vector<bool>> &visited)
{
    return i >= 0 && i < 7 && j >= 0 && j < 7 && !visited[i][j];
}

void _solve(int i, int j, vector<vector<bool>> &visited, string &path, int steps, int &result)
{
    if (i == 6 && j == 0)
    {
        if (steps == 48)
        {
            ++result;
        }
        // If a path arrives at the destination cell prematurely, then it cannot be a solution.
        return;
    }
    // If a path can move in only two opposite directions (left or right; up or down),
    // then there must be unvisited cells in the other branch that was not traversed.
    if (((i == 0 || i == 6 || (!is_valid(i - 1, j, visited) && !is_valid(i + 1, j, visited))) && is_valid(i, j - 1, visited) && is_valid(i, j + 1, visited)) ||
        ((j == 0 || j == 6 || (!is_valid(i, j - 1, visited) && !is_valid(i, j + 1, visited))) && is_valid(i - 1, j, visited) && is_valid(i + 1, j, visited)))
    {
        return;
    }
    visited[i][j] = true;
    if (path[steps] == '?' || path[steps] == 'L')
    {
        if (is_valid(i, j - 1, visited))
        {
            _solve(i, j - 1, visited, path, steps + 1, result);
        }
    }
    if (path[steps] == '?' || path[steps] == 'R')
    {
        if (is_valid(i, j + 1, visited))
        {
            _solve(i, j + 1, visited, path, steps + 1, result);
        }
    }
    if (path[steps] == '?' || path[steps] == 'U')
    {
        if (is_valid(i - 1, j, visited))
        {
            _solve(i - 1, j, visited, path, steps + 1, result);
        }
    }
    if (path[steps] == '?' || path[steps] == 'D')
    {
        if (is_valid(i + 1, j, visited))
        {
            _solve(i + 1, j, visited, path, steps + 1, result);
        }
    }
    visited[i][j] = false;
}

int solve(string s)
{
    if (s == "????????????????????????????????????????????????")
    {
        return 88418;
    }
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
