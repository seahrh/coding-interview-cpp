/*
There are n cities and m roads between them. 
Your task is to process q queries where you have to determine the length of the shortest route between two given cities.
Input
The first input line has three integers n, m and q: the number of cities, roads, and queries.
Then, there are m lines describing the roads.
Each line has three integers a, b and c: there is a road between cities a and b whose length is c.
**All roads are two-way roads.**
Finally, there are q lines describing the queries. 
Each line has two integers a and b: determine the length of the shortest route between cities a and b.
Output
Print the length of the shortest route for each query. If there is no route, print −1 instead.
Constraints
1≤n≤500
1≤m≤n2
1≤q≤10^5
1≤a,b≤n
1≤c≤109
Example

Input:
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2

Output:
5
5
8
-1
3
SOLUTION
All Pairs Shortest Path
Floyd–Warshall algorithm: correct order for the triply nested loops is KIJ.
Time O(N^3)
Space O(N^2): distance matrix

References
- https://usaco.guide/gold/shortest-paths?lang=cpp
- https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html
- https://www.youtube.com/watch?v=oNI0rf2P9gE 
*/
#include <bits/stdc++.h>
#define ll long long
#define tll tuple<long, long>
using namespace std;
const ll maxs = 501;
// LLONG_MAX did not work because of some overflow/underflow issue
const ll inf = 1e18;
vector<vector<ll>> dis(maxs, vector<ll>(maxs, inf));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, q, u, v, w;
    cin >> n >> m >> q;
    while (m--)
    {
        cin >> u >> v >> w;
        dis[u][u] = 0, dis[v][v] = 0;
        dis[u][v] = dis[v][u] = min(dis[u][v], w);
    }
    for (ll k = 1; k < n + 1; k++)
        for (ll i = 1; i < n + 1; i++)
            for (ll j = 1; j < n + 1; j++)
                dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
    while (q--)
    {
        cin >> u >> v;
        ll res = -1;
        if (dis[u][v] < inf)
            res = dis[u][v];
        cout << res << endl;
    }
    return 0;
}