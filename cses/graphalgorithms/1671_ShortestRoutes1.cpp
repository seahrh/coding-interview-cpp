/*
There are n cities and m flight connections between them. 
Your task is to determine the length of the shortest route from Syrjälä to every city.
Input
The first input line has two integers n and m: the number of cities and flight connections. 
The cities are numbered 1,2,…,n, and city 1 is Syrjälä.
After that, there are m lines describing the flight connections. 
Each line has three integers a, b and c: a flight begins at city a, ends at city b, and its length is c. 
Each flight is a one-way flight.
You can assume that it is possible to travel from Syrjälä to all other cities.
Output
Print n integers: the shortest route lengths from Syrjälä to cities 1,2,…,n.
Constraints
1≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
1≤c≤109
Example
Input:
3 4
1 2 6
1 3 2
3 2 3
1 3 4
Output:
0 5 2
SOLUTION
Dijkstra Algorithm: Single Source Shortest Path, Greedy Method
Time O(E lg V): #edges * maintain heap of nodes
Space O(V + E): adjacency list
Dijkstra works on cycles too, so long as all edge weights are non-negative.
Bellman-Ford can handle negative weights but not negative cycles.
*/
#include <bits/stdc++.h>
#define ll long long
#define tll tuple<ll, ll>
using namespace std;
const ll max_size = 2e5 + 1;
// 2-tuple (to_node, weight)
vector<vector<tll>> adj(max_size);
vector<bool> vis(max_size);
// dis[i] = distance from node 1 to node i
vector<ll> dis(max_size, LLONG_MAX);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, u, v, w;
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    dis[1] = 0;
    // `greater` specifies min heap
    // 2-tuple (distance to selected node, selected node)
    priority_queue<tll, vector<tll>, greater<tll>> minh;
    minh.push({0, 1});
    while (!minh.empty())
    {
        u = get<1>(minh.top());
        minh.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto [v, w] : adj[u])
        {
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                minh.push({dis[v], v});
            }
        }
    }
    for (ll i = 1; i < n + 1; i++)
        cout << dis[i] << " ";
    return 0;
}