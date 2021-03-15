/*
Given a string, your task is to generate all different strings that can be created using its characters.
Input
The only input line has a string of length n. Each character is between a–z.
Output
First print an integer k: the number of strings. Then print k lines: the strings in alphabetical order.
Constraints
1≤n≤8
Example
Input:
aabac
Output:
20
aaabc
aaacb
aabac
aabca
aacab
aacba
abaac
abaca
abcaa
acaab
acaba
acbaa
baaac
baaca
bacaa
bcaaa
caaab
caaba
cabaa
cbaaa
SOLUTION
Backtracking to enumerate all possibilities.
Time O(N * N!): N recursive calls.
Inserting the character takes factorial time because there are N! permutations (partials).
Space O(N): recursive call stack
*/
#include <bits/stdc++.h>
using namespace std;

void _solve(string remainder, set<string> &result)
{
    // Base case
    if (remainder.length() == 1)
    {
        result.insert(remainder);
        return;
    }
    char head = remainder.at(0);
    set<string> partials;
    _solve(remainder.substr(1), partials);
    for (string p : partials)
    {
        // add head to the back of the string too!
        int lim = (int)p.size() + 1;
        for (int i = 0; i < lim; i++)
        {
            result.insert(p.substr(0, i) + head + p.substr(i));
        }
    }
}

set<string> solve(string s)
{
    set<string> res;
    _solve(s, res);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    set<string> res = solve(s);
    int k = (int)res.size();
    cout << k << "\n";
    for (string r : res)
    {
        cout << r << "\n";
    }
    return 0;
}