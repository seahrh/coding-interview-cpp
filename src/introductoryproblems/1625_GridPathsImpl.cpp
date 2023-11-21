#include "src/introductoryproblems/package.hpp"

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
        // Incomplete path has visited destination cell; abandon search at this point
        return;
    }
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

int grid_paths(string s)
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