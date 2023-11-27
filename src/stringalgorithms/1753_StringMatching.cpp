/*
Given a string and a pattern, your task is to count the number of positions where the pattern occurs in the string.
Input
The first input line has a string of length n, and the second input line has a pattern of length m.
Both of them consist of characters a–z.
Output
Print one integer: the number of occurrences.
Constraints
1≤n,m≤10^6
Example
Input:
saippuakauppias
pp
Output:
2
SOLUTION
Searching for string s (length m) in string t (length n).
KMP algorithm prefix function build `pi` array:
Time O(N + M)
Space O(N + M)
The prefix function for this string is defined as an array pi of length n,
where pi[i] is the length of the longest proper prefix of the substring s[:i+1]
which is also a proper suffix of this substring.
A proper prefix of a string is a prefix that is not equal to the string itself.
By definition, pi[0]=0.
We generate the string s + '#' + t, where '#' is a separator not present in both s and t.
If pi[i] == m, then s is found (ends at position i).
This length cannot be bigger than M due to the separator.
References
- https://cp-algorithms.com/string/prefix-function.html
- https://www.youtube.com/watch?v=V5-7GzOfADQ
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;

vector<ll> prefix(string s)
{
    ll n = (ll)s.size();
    vector<ll> pi(n);
    for (ll i = 1; i < n; i++)
    {
        ll j = pi[i - 1];
        // prefix is matched except last position
        // pi[j - 1] = length of longest prefix for substr[:j]
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

ll solve(string s, string t)
{
    string st = s + "#" + t;
    vector<ll> pi = prefix(st);
    ll res = 0;
    for (ll i = 0; i < (ll)pi.size(); i++)
        // Values in pi array are 1-indexed
        if (pi[i] == (ll)s.size())
            res++;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> t;
    cin >> s;
    cout << solve(s, t);
    return 0;
}