/*
A game has n levels, connected by m teleporters, and your task is to get from level 1 to level n. 
The game has been designed so that there are no directed cycles in the underlying graph. 
In how many ways can you complete the game?
Input
The first input line has two integers n and m: the number of levels and teleporters. 
The levels are numbered 1,2,…,n.
After this, there are m lines describing the teleporters. 
Each line has two integers a and b: there is a teleporter from level a to level b.
Output
Print one integer: the number of ways you can complete the game. 
Since the result may be large, print it modulo 10^9+7.
Constraints
1≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
Example
Input:
4 5
1 2
2 4
1 3
3 4
1 4
Output:
3
SOLUTION
dp[v] = #paths reaching v
Base case: dp[1] = 1
- Since starting node is 1, there must be 1 path reaching node 1.

Recurrence: dp[v] = sum(dp[u])
- u is a parent node of v

Topological sort so dp[u] must have been computed before dp[v]
Time O(V + E): DFS topsort, DP bottom-up
Space O(V + E): Adjacency list

References
- https://usaco.guide/problems/cses-1681-game-routes/solution
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const ll maxn = 1e5 + 1;
vector<vector<ll>> adj(maxn);
vector<bool> vis(maxn);
vector<ll> ord;
vector<ll> dp(maxn);

// Topological sort on DAG
void dfs(ll s)
{
    if (vis[s])
        return;
    vis[s] = 1;
    for (auto i : adj[s])
        dfs(i);
    // All ancestor nodes (dependencies) have been added to list
    // list is already in sorted order (no need to reverse)
    ord.push_back(s);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, a, b;
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b;
        // directed edges, only insert predecessor!
        adj[b].push_back(a);
    }
    for (ll i = 1; i < n + 1; i++)
        if (!vis[i])
            dfs(i);
    dp[1] = 1;
    for (auto v : ord)
        for (auto u : adj[v])
            (dp[v] += dp[u]) %= mod;
    cout << dp[n];
    return 0;
}
