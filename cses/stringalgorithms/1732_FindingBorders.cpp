/*
A border of a string is a prefix that is also a suffix of the string but not the whole string.
For example, the borders of abcababcab are ab and abcab.
Your task is to find all border lengths of a given string.
Input
The only input line has a string of length n consisting of characters a–z.
Output
Print all border lengths of the string in increasing order.
Constraints
1≤n≤10^6
Example
Input:
abcababcab
Output:
2 5
SOLUTION
KMP algorithm build `pi` array
Time O(N)
Space O(N)
But sorted output requires time O(N lg N). 
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
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    vector<ll> pi = prefix(s);
    set<ll> res;
    ll n = (ll)pi.size();
    // start from tail because prefix must also be suffix
    ll j = pi[n - 1];
    while (j > 0)
    {
        res.insert(j);
        j = pi[j - 1];
    }
    for (auto r : res)
        cout << r << " ";
    return 0;
}