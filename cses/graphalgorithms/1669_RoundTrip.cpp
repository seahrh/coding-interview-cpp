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
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll max_size = 2e5 + 1;
vector<vector<ll>> adj(max_size);
vector<bool> vis(max_size);
vector<ll> cyc;

// returns True if a cycle is found
// remember previous node to prevent backtracking on the cycle
bool dfs(ll s, ll p)
{
    vis[s] = 1;
    for (auto i : adj[s])
    {
        cyc.push_back(i);
        // cycle is found downstream 
        if (!vis[i] && dfs(i, s))
            return 1;
        // return to a visited node; cycle found and terminate
        if (i != p)
            return 1;
        // child cannot be part of the cycle 
        cyc.pop_back();
    }
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
        // head of cycle
        cyc = {i};
        if (!vis[i] && dfs(i, 0))
        {
            // somewhere along the cycle, there are two repeating nodes
            // reverse loop to find another node that matches tail
            ll c = (ll)cyc.size();
            ll j = c - 2;
            while (j >= 0 && cyc[j] != cyc[c - 1])
                j--;
            if (j >= 0)
            {
                vector<ll> path = vector<ll>(cyc.begin() + j, cyc.end());
                cout << path.size() << endl;
                for (auto p : path)
                    cout << p << " ";
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}