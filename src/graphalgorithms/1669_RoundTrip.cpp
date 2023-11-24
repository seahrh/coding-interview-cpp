/*
Byteland has n cities and m roads between them.
Your task is to design a round trip that begins in a city,
goes through two or more other cities, and finally returns to the starting city.
Every intermediate city on the route has to be distinct.
Input
The first input line has two integers n and m: the number of cities and roads.
The cities are numbered 1,2,…,n.
Then, there are m lines describing the roads.
Each line has two integers a and b: there is a road between those cities.
Every road is between two different cities, and there is at most one road between any two cities.
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
5 6
1 3
1 2
5 3
1 5
2 4
4 5
Output:
4
3 5 1 3
SOLUTION
Start DFS on every node to find cycles.
Time O(V+E)
Space O(V+E): adjacency list
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5 + 1;
vector<vector<ll>> adj(N);
// 0=Not visited, 1=Exploring subtree, 2=Done subtree
vector<ll> vis(N);
deque<ll> path;

// returns True if a cycle is found
// remember parent node to avoid premature termination on visited node
// parent node is required for undirected edges
bool dfs(ll s, ll p)
{
    vis[s] = 1;
    for (auto i : adj[s])
    {
        // cycle is found downstream
        if (!vis[i] && dfs(i, s))
        {
            path.push_front(i);
            return 1;
        }
        // return to a visited node; cycle found
        // add tail of cycle (first node in path)
        if (i != p && vis[i] == 1)
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
    ll n, m;
    cin >> n >> m;
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (ll i = 1; i < n + 1; i++)
    {
        path = {};
        if (!vis[i] && dfs(i, 0))
        {
            path.push_front(i);
            // head and tail of cycle must be the same
            while (path.front() != path.back())
                path.pop_front();
            ll len = (ll)path.size();
            // at most one road between any two cities
            if (len >= 4)
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