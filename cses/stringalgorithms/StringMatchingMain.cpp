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
KMP algorithm prefix function build `pi` array:
Time O(N + M)
Space O(N + M)
We generate the string p + \\# + s, where \\# is a separator that appears neither in p nor in s.
Now think about the meaning of the values of the prefix function,
except for the first n+1 entries (which belong to the string p and the separator).
By definition the value pi[i] shows the longest length of a substring ending in position i 
that coincides with the prefix. 
But in our case this is nothing more than the largest block that coincides with p and ends at position i.
This length cannot be bigger than n due to the separator.
But if equality pi[i]=m is achieved, then it means that the string p appears completely (i.e. ends at position i).
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
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

ll solve(string s, string p)
{
    string ps = p + "#" + s;
    vector<ll> pi = prefix(ps);
    ll res = 0;
    for (ll i = 0; i < (ll)pi.size(); i++)
    {
        if (pi[i] == (ll)p.size())
            res++;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, p;
    cin >> s;
    cin >> p;
    cout << solve(s, p);
    return 0;
}