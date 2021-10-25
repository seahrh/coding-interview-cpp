/*
You are given a directed graph, 
and your task is to find out if it contains a negative cycle, and also give an example of such a cycle.
Input
The first input line has two integers n and m: the number of nodes and edges. 
The nodes are numbered 1,2,…,n.
After this, the input has m lines describing the edges. 
Each line has three integers a, b, and c: there is an edge from node a to node b whose length is c.
Output
If the graph contains a negative cycle, print first "YES", and then the nodes in the cycle in their correct order. 
If there are several negative cycles, you can print any of them. If there are no negative cycles, print "NO".
Constraints
1≤n≤2500
1≤m≤5000
1≤a,b≤n
−109≤c≤109
Example
Input:
4 5
1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2
Output:
YES
1 2 4 1
SOLUTION
Bellman-Ford finds single-source shortest paths in a graph
with negative edge weights (but no negative cycles).
The second loop also detects negative cycles.
Time O(VE)

References
- https://web.stanford.edu/class/archive/cs/cs161/cs161.1168/lecture14.pdf
*/
#include <bits/stdc++.h>
#define ll long long
#define t3 tuple<ll, ll, ll>
using namespace std;
const ll maxn = 2501;
// Cannot use LLONG_MAX due to overflow
const ll inf = 1e18;
vector<ll> dis(maxn, inf);
vector<ll> par(maxn);
// edges
vector<t3> es;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, u, v, w, head;
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v >> w;
        es.push_back({u, v, w});
    }
    dis[1] = 0;
    for (ll i = 1; i < n + 1; i++)
        for (auto [u, v, w] : es)
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                par[v] = u;
            }
    // Detects negative cycle
    for (auto [u, v, w] : es)
        // If there is a negative cycle reachable from source node, then:
        if (dis[v] > dis[u] + w)
        {
            cout << "YES" << endl;
            set<ll> seen;
            deque<ll> path;
            head = v;
            // find head of negative cycle
            while (seen.find(head) == seen.end())
            {
                seen.insert(head);
                path.push_front(head);
                head = par[head];
            }
            cout << head << " ";
            for (auto p : path)
            {
                cout << p << " ";
                if (p == head)
                    break;
            }
            return 0;
        }
    cout << "NO";
    return 0;
}
