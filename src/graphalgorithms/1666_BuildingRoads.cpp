/*
Byteland has n cities, and m roads between them.
The goal is to construct new roads so that there is a route between any two cities.
Your task is to find out the minimum number of roads required, and also determine which roads should be built.
Input
The first input line has two integers n and m: the number of cities and roads.
The cities are numbered 1,2,…,n.
After that, there are m lines describing the roads.
Each line has two integers a and b: there is a road between those cities.
A road always connects two different cities, and there is at most one road between any two cities.
Output
First print an integer k: the number of required roads.
Then, print k lines that describe the new roads. You can print any valid solution.
Constraints
1≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
Example
Input:
4 2
1 2
3 4
Output:
1
2 3
SOLUTION
DFS to find connected components.
Store only one member of each connected component in a vector.
Time O(N + M)
Space O(N + M)
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll N = 1e5 + 1;
vector<bool> vis(N);
vector<vector<ll>> adj(N);

void dfs(ll s)
{
    if (vis[s])
        return;
    vis[s] = 1;
    for (auto i : adj[s])
        dfs(i);
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
    vector<ll> res;
    for (ll i = 1; i < n + 1; i++)
    {
        if (!vis[i])
        {
            res.push_back(i);
            dfs(i);
        }
    }
    cout << (ll)res.size() - 1 << endl;
    for (ll i = 0; i < (ll)res.size() - 1; i++)
        cout << res[i] << " " << res[i + 1] << endl;
    return 0;
}