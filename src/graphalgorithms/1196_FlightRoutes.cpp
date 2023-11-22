/*
Your task is to find the k shortest flight routes from Syrjälä to Metsälä.
A route can visit the same city several times.
Note that there can be several routes with the same price and each of them should be considered (see the example).
Input
The first input line has three integers n, m, and k: the number of cities, the number of flights, and the parameter k.
The cities are numbered 1,2,…,n. City 1 is Syrjälä, and city n is Metsälä.
After this, the input has m lines describing the flights.
Each line has three integers a, b, and c: a flight begins at city a, ends at city b, and its price is c.
All flights are one-way flights.
You may assume that there are at least k distinct routes from Syrjälä to Metsälä.
Output
Print k integers: the prices of the k cheapest routes sorted according to their prices.
Constraints
2≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
1≤c≤10^9
1≤k≤10
Example
Input:
4 6 3
1 2 1
1 3 3
2 3 2
2 4 6
3 2 8
3 4 1
Output:
4 4 7
Explanation: The cheapest routes are 1→3→4 (price 4), 1→2→3→4 (price 4) and 1→2→4 (price 7).
SOLUTION
Dijkstra algorithm can be generalized to find the k shortest paths.

References
- https://en.wikipedia.org/wiki/K_shortest_path_routing
*/
#include <bits/stdc++.h>
#define ll long long
#define pai tuple<ll, ll>
using namespace std;
const ll N = 2e5 + 1;
// 2-tuple (to_node, weight)
vector<vector<pai>> adj(N);
// vis[i] = #shortest paths to node i
vector<ll> vis(N);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, k, u, v, w;
    cin >> n >> m >> k;
    while (m--)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    // 2-tuple (distance from start node to end node, end node)
    // `greater` specifies min heap
    priority_queue<tll, vector<tll>, greater<tll>> minh;
    minh.push({0, 1});
    while (!minh.empty() && vis[n] < k)
    {
        ll d = get<0>(minh.top());
        u = get<1>(minh.top());
        minh.pop();
        vis[u]++;
        if (u == n)
            cout << d << " ";
        // Continue to relax edges for the k-th path
        if (vis[u] <= k)
        {
            for (auto [v, w] : adj[u])
                minh.push({d + w, v});
        }
    }
    return 0;
}