/*
You are given a tree consisting of n nodes.
Your task is to determine for each node the sum of the distances from the node to all other nodes.
Input
The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,…,n.
Then there are n−1 lines describing the edges.
Each line contains two integers a and b: there is an edge between nodes a and b.
Output
Print n integers: for each node 1,2,…,n, the sum of the distances.
Constraints
1≤n≤2⋅10^5
1≤a,b≤n
Example
Input:
5
1 2
1 3
3 4
3 5
Output:
6 9 5 8 8
SOLUTION
DP on trees, rerooting technique, 2 rounds of DFS.
DFS 1st round:
dp[i] = sum of distances from i to all other nodes in **subtree rooted at i**
c[i] = number of nodes in **subtree rooted at i**
Recurrence relation:
for i in children:
    dp[parent] += dp[i] + c[i]  (add one for each node in subtree rooted at child)
DFS 2nd round
Rerooting step to account for the rest of the nodes "above" subtree rooted at i.
Redefine dp[i] = sum of distances from i to all other nodes
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
// nodes are 1-indexed
ll N = 2e5 + 1;
vector<vector<ll>> adj(N);
vector<ll> dp(N);
vector<ll> c(N);

void dfs1(ll s, ll parent)
{
    c[s] = 1;
    for (auto i : adj[s])
    {
        if (i != parent)
        {
            dfs1(i, s);
            c[s] += c[i];
            dp[s] += dp[i] + c[i];
        }
    }
}

void dfs2(ll s, ll parent)
{
    if (parent > 0)
    {
        // cut out contribution from subtree rooted at s
        // "above" is the subtree rooted at parent, minus the subtree rooted at child s.
        ll above = dp[parent] - dp[s] - c[s];
        // size of "above" = c[parent] - c[s]
        dp[s] += above + c[parent] - c[s];
        // processing is done before traversing down the tree from node 1
        // so need to update size of subtree!
        // as this value will be used in later computation (size of parent)
        c[s] += c[parent] - c[s];
    }
    for (auto i : adj[s])
    {
        if (i != parent)
            dfs2(i, s);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, a, b;
    cin >> n;
    for (ll i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (ll i = 1; i < n + 1; i++)
    {
        cout << dp[i] << " ";
    }
    return 0;
}