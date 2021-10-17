/*
Given a string and patterns, check for each pattern if it appears in the string.
Input
The first input line has a string of length n.
The next input line has an integer k: the number of patterns. 
Finally, there are k lines that describe the patterns.
The string and the patterns consist of characters a–z.
Output
For each pattern, print "YES" if it appears in the string and "NO" otherwise.
Constraints
1≤n≤10^5
1≤k≤5⋅10^5
the total length of the patterns is at most 5⋅10^5
Example
Input:
aybabtu
3
bab
abc
ayba
Output:
YES
NO
YES
SOLUTION
KMP prefix function, but getting TLE!
Time O(KN)
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> prefix(string s)
{
    ll n = (ll)s.size();
    vector<ll> pi(n);
    for (ll i = 1; i < n; i++)
    {
        ll j = pi[i - 1];
        // prefix is matched except last position i
        // update length of longest proper prefix
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

bool match(string s, string t)
{
    string st = s + "#" + t;
    vector<ll> pi = prefix(st);
    for (ll i = 0; i < (ll)pi.size(); i++)
    {
        // Values in pi array are 1-indexed
        if (pi[i] == (ll)s.size())
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string t;
    cin >> t;
    ll k;
    cin >> k;
    while (k--)
    {
        string s;
        cin >> s;
        if (match(s, t))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
