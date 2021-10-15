/*
Given a string, your task is to determine the longest palindromic substring of the string.
For example, the longest palindrome in aybabtu is bab.
Input
The only input line contains a string of length n. Each character is one of a–z.
Output
Print the longest palindrome in the string. If there are several solutions, you may print any of them.
Constraints
1≤n≤10^6
Example
Input:
aybabtu
Output:
bab
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll expand(string s, ll a, ll b)
{
    while (a >= 0 && b < (ll)s.size() && s[a] == s[b])
    {
        a--;
        b++;
    }
    return b - a - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    ll start = -1, len = 0;
    for (ll i = 0; i < (ll)s.size(); i++)
    {
        ll odd = expand(s, i, i);
        ll even = expand(s, i, i + 1);
        if (odd > len)
        {
            len = odd;
            start = i - (odd / 2);
        }
        if (even > len)
        {
            len = even;
            start = i - (even / 2 - 1);
        }
    }
    cout << s.substr(start, len);
    return 0;
}