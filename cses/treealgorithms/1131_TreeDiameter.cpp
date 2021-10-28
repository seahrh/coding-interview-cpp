/*
You are given a tree consisting of n nodes.
The diameter of a tree is the maximum distance between two nodes.
Your task is to determine the diameter of the tree.
Input
The first input line contains an integer n: the number of nodes. 
The nodes are numbered 1,2,…,n.
Then there are n−1 lines describing the edges.
Each line contains two integers a and b: there is an edge between nodes a and b.
Output
Print one integer: the diameter of the tree.
Constraints
1≤n≤2⋅10^5
1≤a,b≤n
Example
Input:
5
1 2
1 3
3 4
3 5
Output:
3
Explanation: The diameter corresponds to the path 2→1→3→5.
SOLUTION
Observe that the longest path will always occur between two leaf nodes( nodes having only one edge linked).
This can also be proved by contradiction 
that if longest path is between two nodes and either or both of two nodes is not a leaf node 
then we can extend the path to get a longer path.

Start DFS/BFS from a random node and then see which node is farthest from it. 
Let the node farthest be x. It is clear that x is a leaf node. 
Now if we start DFS/BFS from x and check farthest node from it, we will get our answer.
Time O(V + E)
Space O(V + E)

References
- https://cs.stackexchange.com/questions/22855/algorithm-to-find-diameter-of-a-tree-using-bfs-dfs-why-does-it-work
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll max_size = 2e5 + 1;
vector<vector<ll>> adj(max_size);
// x is the node furthest away from the start node.
// d is the distance to x
ll d = 0, x = 0;

// dist is the current length of the path beginning from 1st node
void dfs(ll s, ll parent, ll dist)
{
    for (auto i : adj[s])
        if (i != parent)
            dfs(i, s, dist + 1);
    if (dist > d)
    {
        d = dist;
        x = s;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // get first leaf node
    dfs(1, 0, 0);
    // get second leaf node
    dfs(x, 0, 0);
    cout << d;
    return 0;
}