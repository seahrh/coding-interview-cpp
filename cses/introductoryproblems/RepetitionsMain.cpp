/*
You are given a DNA sequence: a string consisting of characters A, C, G, and T.
Find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.
Input
The only input line contains a string of n characters.
Output
Print one integer: the length of the longest repetition.
Constraints
1≤n≤10^6
Example
Input:
ATTCGGGA
Output:
3
SOLUTION
Time O(N)
Space O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{
    int best = 1, curr = 1;
    int s_len = (int)s.size();
    char prev = s.at(0);
    for (int i = 1; i < s_len; i++)
    {
        if (s.at(i) == prev)
        {
            best = max(best, ++curr);
        }
        else
        {
            curr = 1;
        }
        prev = s.at(i);
    }
    return best;
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
