/*
You are given a string of length n and a dictionary containing k words.
In how many ways can you create the string using the words?
Input
The first input line has a string containing n characters between a–z.
The second line has an integer k: the number of words in the dictionary.
Finally there are k lines describing the words. Each word is unique and consists of characters a–z.
Output
Print the number of ways modulo 10^9+7.
Constraints
1≤n≤5000
1≤k≤10^5
the total length of the words is at most 10^6
Example
Input:
ababc
4
ab
abab
c
cb
Output:
2
Explanation: The possible ways are ab+ab+c and abab+c.
SOLUTION
dp[i] = number of word combinations for suffix s[i:]
Recurring relation
If char at position i matches, then dp[i] += dp[i+1]
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
vector<vector<ll>> trie(1'000'001, vector<ll>(26));
vector<bool> stop(1'000'001);
vector<ll> dp(5005, 0);

ll add(string s, ll new_node)
{
    ll node = 0;
    for (ll i = 0; i < (ll)s.size(); i++)
    {
        ll j = s[i] - 'a';
        if (!trie[node][j])
        {
            // create new node
            trie[node][j] = new_node++;
        }
        node = trie[node][j];
    }
    stop[node] = 1;
    return new_node;
}

ll find(string s, ll head)
{
    ll node = 0, ans = 0;
    for (ll i = head; i < (ll)s.size(); i++)
    {
        // Stop DFS of trie if suffix cannot be completely matched.
        if (!trie[node][s[i] - 'a'])
            return ans;
        node = trie[node][s[i] - 'a'];
        if (stop[node])
        {
            (ans += dp[i + 1]) %= mod;
        }
    }
    return ans;
}

ll solve(string s)
{

    // Base case: always possible to match zero-length string
    dp[(ll)s.size()] = 1;
    // all suffixes of s for whole-string matching
    for (ll i = s.size() - 1; i >= 0; i--)
    {
        dp[i] = find(s, i);
    }
    return dp[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    ll k;
    cin >> k;
    ll node = 1;
    while (k--)
    {
        string x;
        cin >> x;
        node = add(x, node);
    }
    cout << solve(s);
    return 0;
}
