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

string solve(string s)
{
    ll n = (ll)s.size();
    vector<ll> dp(n, 1);
    ll start = 0, len = 1;
    for (ll i = n - 2; i >= 0; i--)
    {
        if (s[i] == s[i + 1])
        {
            dp[i] = dp[i + 1] + 1;
        }
    }
    for (ll i = n - 3; i >= 0; i--)
    {
        ll j = i + 1 + dp[i + 1];
        if (j < n && s[i] == s[j])
            dp[i] = max(dp[i], dp[i + 1] + 2);
    }
    for (ll i = 0; i < n; i++)
    {
        if (dp[i] > len)
        {
            len = dp[i];
            start = i;
        }
    }
    return s.substr(start, len);
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