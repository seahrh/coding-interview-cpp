/*
Syrjälä's network has n computers and m connections. 
Your task is to find out if Uolevi can send a message to Maija, 
and if it is possible, what is the minimum number of computers on such a route.
Input
The first input line has two integers n and m: the number of computers and connections.
The computers are numbered 1,2,…,n. Uolevi's computer is 1 and Maija's computer is n.
Then, there are m lines describing the connections. 
Each line has two integers a and b: there is a connection between those computers.
Every connection is between two different computers, and there is at most one connection between any two computers.
Output
If it is possible to send a message, 
first print k: the minimum number of computers on a valid route. 
After this, print an example of such a route. You can print any valid solution.
If there are no routes, print "IMPOSSIBLE".
Constraints
2≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
Example
Input:
5 5
1 2
1 3
1 4
2 3
5 4
Output:
3
1 4 5
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll max_size = 1e5 + 1;
vector<bool> vis(max_size);
vector<vector<ll>> adj(max_size);
vector<ll> parent(max_size);

void bfs(ll s)
{
    vis[s] = 1;
    deque<ll> q;
    q.push_front(s);
    while (!q.empty())
    {
        ll curr = q.front();
        q.pop_front();
        for (auto i : adj[curr])
        {
            if (vis[i])
                continue;
            vis[i] = 1;
            parent[i] = curr;
            q.push_front(i);
        }
    }
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
    bfs(1);
    if (!vis[n])
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    deque<ll> path;
    ll i = n;
    while (i != 1)
    {
        path.push_front(i);
        i = parent[i];
    }
    path.push_front(1);
    cout << path.size() << endl;
    for (auto p : path)
        cout << p << " ";
    return 0;
}