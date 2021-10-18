/*
There are n pupils in Uolevi's class, and m friendships between them. 
Your task is to divide the pupils into two teams in such a way that no two pupils in a team are friends. 
You can freely choose the sizes of the teams.
Input
The first input line has two integers n and m: the number of pupils and friendships. 
The pupils are numbered 1,2,…,n.
Then, there are m lines describing the friendships. 
Each line has two integers a and b: pupils a and b are friends.
Every friendship is between two different pupils. 
You can assume that there is at most one friendship between any two pupils.
Output
Print an example of how to build the teams. 
For each pupil, print "1" or "2" depending on to which team the pupil will be assigned. You can print any valid team.
If there are no solutions, print "IMPOSSIBLE".
Constraints
1≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
Example
Input:
5 3
1 2
1 3
4 5
Output:
1 2 2 1 2
SOLUTION
BFS to set the colors of bipartite graph
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll max_size = 2e5 + 1;
vector<vector<ll>> adj(max_size);
vector<bool> vis(max_size);
// col[i] = colour of node i
vector<ll> col(max_size);

bool bfs(ll s)
{
    vis[s] = 1;
    col[s] = 1;
    deque<ll> q;
    q.push_back(s);
    while (!q.empty())
    {
        s = q.front();
        q.pop_front();
        for (auto i : adj[s])
        {
            // must preserve bipartite property
            // terminate if color of child is set and equals parent's color
            if (col[i] == col[s])
                return 0;
            if (vis[i])
                continue;
            vis[i] = 1;
            col[i] = (col[s] == 1 ? 2 : 1);
            q.push_back(i);
        }
    }
    return 1;
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
        // short circuit eval
        if (!vis[i] && !bfs(i))
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    for (ll i = 1; i < n + 1; i++)
    {
        cout << col[i] << " ";
    }
    return 0;
}