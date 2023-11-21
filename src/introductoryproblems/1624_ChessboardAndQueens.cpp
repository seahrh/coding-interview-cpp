/*
Your task is to place eight queens on a chessboard so that no two queens are attacking each other.
As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares.
However, the reserved squares do not prevent queens from attacking each other.
How many possible ways are there to place the queens?
Input
The input has eight lines, and each of them has eight characters. Each square is either free (.) or reserved (*).
Output
Print one integer: the number of ways you can place the queens.
Example
Input:
........
........
..*.....
........
........
.....**.
...*....
........
Output:
65
SOLUTION
- Backtracking to find all possible placements
- Grow the state space tree by placing a queen on one row at a time
- Bounding function: no two queens share the same row, column and diagonal.
Time O(N!)
The worst case “brute force” solution for the N-queens puzzle has an O(N^2) time complexity.
This means it will look through every position on an NxN board, N times for N queens.
It is by far the slowest and most impractical method.
If you refactor and prevent it from checking queens occupying the same row as each other,
it will still be brute force,
but the possible board states drop from 16,777,216 to a little over 40,000 and has a time complexity of O(N!).
*/
#include <bits/stdc++.h>
using namespace std;

bool is_safe(int ai, int aj, int bi, int bj)
{
    if (ai == bi)
    {
        return false;
    }
    if (aj == bj)
    {
        return false;
    }
    return abs(ai - bi) != abs(aj - bj);
}

void _solve(vector<string> &board, vector<tuple<int, int>> partial, int &result)
{
    int len = (int)board.size();
    // evaluate candidate placement in row i
    int i = (int)partial.size();
    if (i == len)
    {
        result++;
        return;
    }
    for (int j = 0; j < len; j++)
    {
        if (board[i][j] == '*')
        {
            continue;
        }
        bool is_valid = true;
        for (tuple<int, int> t : partial)
        {
            if (!is_safe(i, j, get<0>(t), get<1>(t)))
            {
                is_valid = false;
                break;
            }
        }
        if (!is_valid)
        {
            continue;
        }
        // partial is passed by value so it is safe to reference partial
        vector<tuple<int, int>> p = partial;
        p.push_back(make_tuple(i, j));
        _solve(board, p, result);
    }
}

int solve(vector<string> board)
{
    int res = 0;
    vector<tuple<int, int>> partial;
    _solve(board, partial, res);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> board(8);
    for (int i = 0; i < 8; i++)
    {
        cin >> board[i];
    }
    cout << solve(board);
    return 0;
}