/*
A Gray code is a list of all 2n bit strings of length n, 
where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).
Your task is to create a Gray code for a given length n.
Input
The only input line has an integer n.
Output
Print 2n lines that describe the Gray code. You can print any valid solution.
Constraints
1≤n≤16
Example
Input:
2
Output:
00
01
11
10
SOLUTION
Backtracking
Time O(2^N)
Space O(N): depth of recursive call stack
See https://leetcode.com/problems/gray-code/discuss/29880/Backtracking-C%2B%2B-solution
*/
#include <bits/stdc++.h>
using namespace std;

// n is which bit to flip
void _solve(int n, string &partial, vector<string> &result)
{
    // partial must be passed by reference to maintain gray-code order!
    // partial is passed from left recursion subtree to the right.
    // Base case: no more bit flipping
    if (n == 0)
    {
        result.push_back(partial);
        return;
    }
    _solve(n - 1, partial, result);
    // flip it
    if (partial[n - 1] == '0')
    {
        partial[n - 1] = '1';
    }
    else
    {
        partial[n - 1] = '0';
    }
    _solve(n - 1, partial, result);
}

vector<string> solve(int n)
{
    vector<string> res;
    string zeroes(n, '0');
    _solve(n, zeroes, res);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> res = solve(n);
    for (string s : res)
    {
        cout << s << "\n";
    }
    return 0;
}