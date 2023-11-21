/*
The Tower of Hanoi game consists of three stacks (left, middle and right) and n round disks of different sizes.
Initially, the left stack has all the disks, in increasing order of size from top to bottom.
The goal is to move all the disks to the right stack using the middle stack.
On each move you can move the uppermost disk from a stack to another stack.
In addition, it is not allowed to place a larger disk on a smaller disk.
Your task is to find a solution that minimizes the number of moves.
Input
The only input line has an integer n: the number of disks.
Output
First print an integer k: the minimum number of moves.
After this, print k lines that describe the moves. Each line has two integers a and b: you move a disk from stack a to stack b.
Constraints
1≤n≤16
Example
Input:
2
Output:
3
1 2
1 3
2 3
SOLUTION
Move a tower of height-1 to the MID pole, using the RIGHT pole as buffer.
Move the remaining disk to the RIGHT pole.
Move the tower of height-1 from the MID pole to the RIGHT pole, using the LEFT pole as buffer.
Time O(2^N)
Space O(N): depth of recursive call stack
*/
#include <bits/stdc++.h>
using namespace std;

void _solve(int n, int from, int to, int buf, vector<tuple<int, int>> &moves)
{
    // Base case: no more disks to move
    if (n == 0)
    {
        return;
    }
    _solve(n - 1, from, buf, to, moves);
    moves.push_back(make_tuple(from, to));
    _solve(n - 1, buf, to, from, moves);
}

vector<tuple<int, int>> solve(int n)
{
    vector<tuple<int, int>> res;
    _solve(n, 1, 3, 2, res);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<tuple<int, int>> res = solve(n);
    cout << res.size() << "\n";
    for (tuple<int, int> r : res)
    {
        cout << get<0>(r) << " " << get<1>(r) << "\n";
    }
    return 0;
}
