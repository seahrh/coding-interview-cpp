/*
You are given a tree consisting of n nodes.
Your task is to determine for each node the maximum distance to another node.
Input
The first input line contains an integer n: the number of nodes.
The nodes are numbered 1,2,…,n.
Then there are n−1 lines describing the edges.
Each line contains two integers a and b: there is an edge between nodes a and b.
Output
Print n integers: for each node 1,2,…,n, the maximum distance to another node.
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
2 3 2 3 3
SOLUTION
Three rounds of DFS
1. Starting from node 1, find leaf node a (one end of the tree diameter).
2. Starting from node a, find leaf node b (other end of the tree diameter).
   Compute distance from a (origin=0) to every other node.
3. Starting from node b, compute distance from b (origin=1) to every other node

References
- https://usaco.guide/problems/cses-1132-tree-distances-i/solution
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
// nodes are 1-indexed
ll N = 2e5 + 1;
vector<vector<ll>> adj(N);
// dist[i][0] = distance from 1st leaf node to node i
// dist[i][1] = distance from 2nd leaf node to node i
vector<vector<ll>> dist(N, vector<ll>(2));

// return node furthest away from origin (either 1st or 2nd leaf node)
ll dfs(ll s, ll parent, ll d, ll origin)
{
    dist[s][origin] = d;
    ll res = s;
    for (ll i : adj[s])
        if (i != parent)
        {
            ll x = dfs(i, s, d + 1, origin);
            if (dist[x][origin] > dist[res][origin])
                res = x;
        }
    return res;
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
    // first leaf node (furthest from node 1)
    a = dfs(1, 0, 0, 0);
    // second leaf node
    b = dfs(a, 0, 0, 0);
    dfs(b, 0, 0, 1);
    for (ll i = 1; i < n + 1; i++)
        cout << max(dist[i][0], dist[i][1]) << " ";
    return 0;
}