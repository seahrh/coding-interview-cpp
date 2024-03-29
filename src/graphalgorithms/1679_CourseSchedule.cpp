/*
You have to complete n courses.
There are m requirements of the form "course a has to be completed before course b".
Your task is to find an order in which you can complete the courses.
Input
The first input line has two integers n and m: the number of courses and requirements.
The courses are numbered 1,2,…,n.
After this, there are m lines describing the requirements.
Each line has two integers a and b: course a has to be completed before course b.
Output
Print an order in which you can complete the courses. You can print any valid order that includes all the courses.
If there are no solutions, print "IMPOSSIBLE".
Constraints
1≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
Example
Input:
5 3
1 2
3 1
4 5
Output:
3 4 1 5 2
SOLUTION
Tour where all n nodes must be visited.
DFS does 2 things
- Detect cycle (ensure it is a DAG)
- Topological sort

References
- https://www.youtube.com/watch?v=rKQaZuoUR4M
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 1;
vector<vector<ll>> adj(N);
vector<bool> vis(N);
// marker for cycle finding: 0=Not visited, 1=Exploring subtree, 2=Done subtree
vector<ll> mar(N);
vector<ll> path;

// Topological sort on DAG
void dfs(ll s)
{
    if (vis[s])
        return;
    vis[s] = 1;
    for (auto i : adj[s])
        dfs(i);
    // All ancestor nodes (predecessors) have been added to list
    // list is already in sorted order (no need to reverse)
    path.push_back(s);
}

bool cycle(ll s)
{
    mar[s] = 1;
    for (auto i : adj[s])
    {
        // cycle is found downstream
        if (!mar[i] && cycle(i))
            return 1;
        // return to a visited node; cycle found
        if (mar[i] == 1)
            return 1;
    }
    mar[s] = 2;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, a, b;
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b;
        // directed edges, only insert predecessor!
        adj[b].push_back(a);
    }
    for (ll i = 1; i < n + 1; i++)
    {
        if (!mar[i] && cycle(i))
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
        // Topological sort on this connected component
        if (!vis[i])
            dfs(i);
    }
    for (auto p : path)
        cout << p << " ";
    return 0;
}