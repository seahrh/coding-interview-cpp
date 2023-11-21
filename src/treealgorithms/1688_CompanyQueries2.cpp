/*
A company has n employees, who form a tree hierarchy where each employee has a boss, except for the general director.
Your task is to process q queries of the form: who is the lowest common boss of employees a and b in the hierarchy?
Input
The first input line has two integers n and q: the number of employees and queries. 
The employees are numbered 1,2,…,n, and employee 1 is the general director.
The next line has n−1 integers e2,e3,…,en: for each employee 2,3,…,n their boss.
Finally, there are q lines describing the queries. 
Each line has two integers a and b: who is the lowest common boss of employees a and b?
Output
Print the answer for each query.
Constraints
1≤n,q≤2⋅10^5
1≤ei≤i−1
1≤a,b≤n
Example
Input:
5 3
1 1 3 3
4 5
2 5
1 4
Output:
3
1
1
SOLUTION
Binary Lifting to find the lowest common ancestor of two nodes in a tree.
Build DP table
Time O(N lg N)
Space O(N lg N)
Query
Time O(lg N)
References
- https://www.youtube.com/watch?v=dOAxrhAUIhA
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll maxn = 2e5 + 1;
ll maxk = (ll)log2(maxn) + 1;
vector<vector<ll>> dp(maxn, vector<ll>(maxk));
vector<vector<ll>> adj(maxn);
// Level
vector<ll> lev(maxn);

void dfs(ll s, ll p)
{
    for (auto i : adj[s])
    {
        if (i != p)
        {
            lev[i] = lev[s] + 1;
            dfs(i, s);
        }
    }
}

ll lca(ll a, ll b)
{
    // Level of a <= b (b is deeper in the tree)
    if (lev[a] > lev[b])
        swap(a, b);
    // find the ancestor of b at the same level as a
    for (ll k = maxk; k >= 0; k--)
        if (lev[b] - (ll)pow(2, k) >= lev[a])
            b = dp[b][k];
    // this guard condition prevents the rest of the solution
    // from returning the parent of LCA (overshoot LCA by 1)
    if (a == b)
        return b;
    // from below, get as close as possible to LCA
    // check for inequality because equality can overshoot LCA
    for (ll k = maxk; k >= 0; k--)
        if (dp[a][k] != dp[b][k])
            a = dp[a][k], b = dp[b][k];
    return dp[b][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q, x, a, b;
    cin >> n >> q;
    // Base case: immediate ancestors
    for (int i = 2; i < n + 1; i++)
    {
        cin >> x;
        dp[i][0] = x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    for (ll i = 2; i < n + 1; i++)
        for (ll j = 1; j < maxk + 1; j++)
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
    dfs(1, 0);
    while (q--)
    {
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
    return 0;
}