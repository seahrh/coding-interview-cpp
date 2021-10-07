/*
Given a string, your task is to reorder its letters in such a way that it becomes a palindrome
(i.e., it reads the same forwards and backwards).
Input
The only input line has a string of length n consisting of characters A–Z.
Output
Print a palindrome consisting of the characters of the original string. You may print any valid solution.
If there are no solutions, print "NO SOLUTION".
Constraints
1≤n≤10^6
Example
Input:
AAAACACBA
Output:
AACABACAA
SOLUTION
Find the single character that has odd count.
Palindrome cannot have more than 1 char with odd count e.g. ___AB___  where A and B have odd count.
Time O(N)
Space O(N)
*/
#include <bits/stdc++.h>
using namespace std;

optional<string> solve(string s)
{
    string left = "", mid = "", right;
    set<char> odd;
    for (char c : s)
    {
        auto it = odd.find(c);
        if (it == odd.end())
        {
            odd.insert(c);
        }
        else
        {
            odd.erase(c);
            left += c;
        }
    }
    if (odd.size() > 1)
    {
        return {};
    }
    right = left;
    reverse(right.begin(), right.end());
    if (odd.begin() != odd.end())
    {
        // at most one char! The rest has been added to `left`.
        mid = *odd.begin();
    }
    return left + mid + right;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    optional<string> res = solve(s);
    if (res)
    {
        cout << res.value();
    }
    else
    {
        cout << "NO SOLUTION";
    }
    return 0;
}