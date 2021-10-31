/*
Uolevi has won a contest, and the prize is a free flight trip that can consist of one or more flights through cities. 
Of course, Uolevi wants to choose a trip that has as many cities as possible.
Uolevi wants to fly from Syrjälä to Lehmälä so that he visits the maximum number of cities. 
You are given the list of possible flights, and you know that there are no directed cycles in the flight network.
Input
The first input line has two integers n and m: the number of cities and flights. 
The cities are numbered 1,2,…,n. City 1 is Syrjälä, and city n is Lehmälä.
After this, there are m lines describing the flights. 
Each line has two integers a and b: there is a flight from city a to city b. Each flight is a one-way flight.
Output
First print the maximum number of cities on the route. 
After this, print the cities in the order they will be visited. You can print any valid solution.
If there are no solutions, print "IMPOSSIBLE".
Constraints
2≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
Example
Input:
5 5
1 2
2 5
1 3
3 4
4 5
Output:
4
1 3 4 5
SOLUTION
dp[v] = length of the longest path reaching v
Base case: dp[1] = 1
- Assume nodes 1 and n are in the same connected component
- Ignore other starting nodes in the case of connected components

Recurrence: dp[v] = max(dp[u]) + 1  
- u is one of the parents

Topological sort so dp[u] must have been computed before dp[v]
Time O(V + E): DFS topsort, DP longest path
Space O(V + E): Adjacency list

References
- https://usaco.guide/problems/cses-1681-game-routes/solution
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll maxn = 1e5 + 1;
vector<vector<ll>> adj(maxn);
vector<bool> vis(maxn);
vector<ll> ord;
vector<ll> dp(maxn);
vector<ll> par(maxn);

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
    {
        ll mx = 0;
        for (auto u : adj[v])
        {
            if (dp[u] > mx)
            {
                mx = dp[u];
                par[v] = u;
            }
        }
        // Exclude other starting nodes besides 1
        if (mx > 0)
            dp[v] += mx + 1;
    }
    deque<ll> res = {n};
    ll i = n;
    while (par[i])
    {
        res.push_front(par[i]);
        i = par[i];
    }
    ll len = (ll)res.size();
    if (len < 2)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << len << endl;
    for (auto r : res)
        cout << r << " ";
    return 0;
}