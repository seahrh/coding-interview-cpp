/*
You are going to travel from Syrjälä to Lehmälä by plane. You would like to find answers to the following questions:
what is the minimum price of such a route?
how many minimum-price routes are there? (modulo 10^9+7)
what is the minimum number of flights in a minimum-price route?
what is the maximum number of flights in a minimum-price route?
Input
The first input line contains two integers n and m: the number of cities and the number of flights. 
The cities are numbered 1,2,…,n. City 1 is Syrjälä, and city n is Lehmälä.
After this, there are m lines describing the flights. 
Each line has three integers a, b, and c: there is a flight from city a to city b with price c. All flights are one-way flights.
You may assume that there is a route from Syrjälä to Lehmälä.
Output
Print four integers according to the problem statement.
Constraints
1≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
1≤c≤109
Example
Input:
4 5
1 4 5
1 2 4
2 4 5
1 3 2
3 4 3
Output:
5 2 1 2
SOLUTION
dp[v] = #paths reaching node v
Base case: dp[1] = 1
- Since starting node is 1, there must be 1 path reaching node 1.
Recurrence: dp[v] = sum(dp[u])
- u is a parent node of v

dp[v] = min #nodes in paths reaching v
Base case: dp[1] = 1
- Since starting node is 1, path length = 1
Recurrence: dp[v] = min(dp[u]) + 1
- u is a parent node of v

Ordering of nodes in shortest paths, so dp[u] must have been computed before dp[v].
*/
#include <bits/stdc++.h>
#define ll long long
#define tll tuple<ll, ll>
using namespace std;
const ll mod = 1e9 + 7;
const ll maxn = 1e5 + 1;
const ll inf = 1e18;
vector<bool> vis(maxn);
// 2-tuple (to_node, weight)
vector<vector<tll>> adj1(maxn);
// adj2 contains predecessors (weight not needed!)
vector<vector<ll>> adj2(maxn);
vector<ll> ord;
vector<ll> dp1(maxn), dp2(maxn), dp3(maxn);

vector<ll> dij(ll s)
{
    // dis[i] = distance from starting node to node i
    vector<ll> dis(maxn, inf);
    dis[s] = 0;
    // `greater` specifies min heap
    // 2-tuple (distance to selected node, selected node)
    priority_queue<tll, vector<tll>, greater<tll>> minh;
    minh.push({0, s});
    while (!minh.empty())
    {
        ll u = get<1>(minh.top());
        minh.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto [v, w] : adj1[u])
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                minh.push({dis[v], v});
            }
    }
    return dis;
}

// Ordering of nodes in shortest paths
void dfs(ll s)
{
    if (vis[s])
        return;
    vis[s] = 1;
    for (auto i : adj2[s])
        dfs(i);
    // all predecessors (dependencies) are already inserted
    ord.push_back(s);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, u, v, w;
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v >> w;
        adj1[u].push_back({v, w});
    }
    // dis[i] = shortest distance from starting node to i
    vector<ll> dis = dij(1);
    // adj2 is adjacency list for shortest paths
    for (u = 1; u < n + 1; u++)
        for (auto [v, w] : adj1[u])
            if (dis[v] == dis[u] + w)
                // insert predecessor!
                adj2[v].push_back(u);
    // reset visited array
    vis = vector<bool>(maxn);
    for (ll i = 1; i < n + 1; i++)
        if (!vis[i])
            dfs(i);
    // Base case
    dp1[1] = 1, dp2[1] = 1, dp3[1] = 1;
    for (auto v : ord)
    {
        ll mn = inf, mx = 0;
        for (auto u : adj2[v])
        {
            (dp1[v] += dp1[u]) %= mod;
            mn = min(mn, dp2[u]);
            mx = max(mx, dp3[u]);
        }
        if (mn != inf)
            dp2[v] = mn + 1;
        if (mx != 0)
            dp3[v] = mx + 1;
    }
    // minus 1 because question asks for #flights
    cout << dis[n] << " " << dp1[n] << " " << dp2[n] - 1 << " " << dp3[n] - 1;
    return 0;
}