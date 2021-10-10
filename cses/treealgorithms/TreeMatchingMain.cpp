/*
You are given a tree consisting of n nodes.
A matching is a set of edges where each node is an endpoint of at most one edge.
What is the maximum number of edges in a matching?
Input
The first input line contains an integer n: the number of nodes.
The nodes are numbered 1,2,…,n.
Then there are n−1 lines describing the edges.
Each line contains two integers a and b: there is an edge between nodes a and b.
Output
Print one integer: the maximum number of pairs.
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
2
Explanation: One possible matching is (1,2) and (3,4).
SOLUTION
Greedy method: DFS traverse to the leaf node and "match" the edge if available.
Time O(N)
Space O(N^2)
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll max_size = (ll)2e5 + 1;
vector<vector<ll>> adj(max_size);
vector<ll> vis(max_size);
ll res = 0;

void dfs(ll s, ll parent)
{
    for (auto i : adj[s])
    {
        if (i != parent)
        {
            dfs(i, s);
            if (!vis[i] && !vis[s])
            {
                vis[i] = 1, vis[s] = 1;
                res++;
            }
        }
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
    dfs(1, 0);
    cout << res;
    return 0;
}