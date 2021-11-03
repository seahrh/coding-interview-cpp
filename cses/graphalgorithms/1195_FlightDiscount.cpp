/*
Your task is to find a minimum-price flight route from Syrjälä to Metsälä. 
You have one discount coupon, using which you can halve the price of any single flight during the route. 
However, you can only use the coupon once.
Input
The first input line has two integers n and m: the number of cities and flight connections. 
The cities are numbered 1,2,…,n. City 1 is Syrjälä, and city n is Metsälä.
After this there are m lines describing the flights. 
Each line has three integers a, b, and c: a flight begins at city a, ends at city b, and its price is c. 
Each flight is unidirectional.
You can assume that it is always possible to get from Syrjälä to Metsälä.
Output
Print one integer: the price of the cheapest route from Syrjälä to Metsälä.
When you use the discount coupon for a flight whose price is x, 
its price becomes ⌊x/2⌋ (it is rounded down to an integer).
Constraints
2≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
1≤c≤10^9
Example
Input:
3 4
1 2 3
2 3 1
1 3 7
2 1 5
Output:
2
SOLUTION
Dijkstra single source shortest path; no negative weights.
Two rounds from starting nodes 1 and n.
min_cost = dist(1,u) + discount(u,v) + dist(v,n)

References
- https://usaco.guide/problems/cses-1195-flight-discount/solution
*/
#include <bits/stdc++.h>
#define ll long long
#define tll tuple<ll, ll>
using namespace std;
const ll maxn = 1e5 + 1;
const ll inf = 1e18;
// 2-tuple (to_node, weight)
vector<vector<tll>> adj1(maxn);
vector<vector<tll>> adj2(maxn);

vector<ll> dij(ll s, vector<vector<tll>> adj)
{
    vector<bool> vis(maxn);
    // dis[i] = distance from starting node (1 or n) to node i
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
        for (auto [v, w] : adj[u])
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                minh.push({dis[v], v});
            }
    }
    return dis;
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
        adj2[v].push_back({u, w});
    }
    // distance from node 1 to i
    vector<ll> dis1 = dij(1, adj1);
    // shortest distance from node n to i
    vector<ll> dis2 = dij(n, adj2);
    ll mn = inf;
    for (u = 1; u < n; u++)
        for (auto [v, w] : adj1[u])
            mn = min(mn, dis1[u] + dis2[v] + w / 2);
    cout << mn;
    return 0;
}