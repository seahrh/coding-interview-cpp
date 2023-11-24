/*
Byteland has n cities and m flight connections.
Your task is to design a round trip that begins in a city, goes through one or more other cities,
and finally returns to the starting city. Every intermediate city on the route has to be distinct.
Input
The first input line has two integers n and m: the number of cities and flights.
The cities are numbered 1,2,…,n.
Then, there are m lines describing the flights.
Each line has two integers a and b: there is a flight connection from city a to city b.
All connections are one-way flights from a city to another city.
Output
First print an integer k: the number of cities on the route.
Then print k cities in the order they will be visited. You can print any valid solution.
If there are no solutions, print "IMPOSSIBLE".
Constraints
1≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
Example
Input:
4 5
1 3
2 1
2 4
3 2
3 4
Output:
4
2 1 3 2
SOLUTION
Start DFS on every node to find cycles.
Time O(V+E)
Space O(V+E): adjacency list
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 1;
vector<vector<ll>> adj(N);
// 0=Not visited, 1=Exploring subtree, 2=Done subtree
vector<ll> vis(N);
deque<ll> path;

// returns True if a cycle is found
bool dfs(ll s)
{
    vis[s] = 1;
    for (auto i : adj[s])
    {
        // cycle is found downstream
        if (!vis[i] && dfs(i))
        {
            path.push_front(i);
            return 1;
        }
        // return to a visited node; cycle found
        // add tail of cycle (first node in path)
        if (vis[i] == 1)
        {
            path.push_front(i);
            return 1;
        }
    }
    vis[s] = 2;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, u, v;
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (ll i = 1; i < n + 1; i++)
    {
        path = {};
        if (!vis[i] && dfs(i))
        {
            path.push_front(i);
            // head and tail of cycle must be the same
            while (path.front() != path.back())
                path.pop_front();
            ll len = (ll)path.size();
            if (len >= 3)
            {
                cout << len << endl;
                for (auto p : path)
                    cout << p << " ";
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}