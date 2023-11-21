/*
You are given a map of a labyrinth, and your task is to find a path from start to end.
You can walk left, right, up and down.
Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the labyrinth.
Each character is . (floor), # (wall), A (start), or B (end). There is exactly one A and one B in the input.
Output
First print "YES", if there is a path, and "NO" otherwise.
If there is a path, print the length of the shortest such path 
and its description as a string consisting of characters L (left), R (right), U (up), and D (down). 
You can print any valid solution.
Constraints
1≤n,m≤1000
Example
Input:
5 8
########
#.A#...#
#.##.#B#
#......#
########
Output:
YES
9
LDDRRRRRU
SOLUTION
Find all possible paths from starting position using BFS.
if all of the edges in a graph are unweighted (or the same weight)
then the first time a node is visited is the shortest path to that node from the source node.
Time O(NM)
Space O(NM)
References
- https://stackoverflow.com/questions/8379785/how-does-a-breadth-first-search-work-when-looking-for-shortest-path
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<bool> vis(1'000'000);
// build adjacency list for floor tiles only
vector<vector<ll>> adj(1'000'000);
vector<ll> parent(1'000'000);
queue<ll> q;

void bfs(ll s)
{
    vis[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        ll curr = q.front();
        q.pop();
        for (auto i : adj[curr])
        {
            if (vis[i])
                continue;
            // process the node before enqueue
            // queue is for exploring neighbour nodes
            vis[i] = 1;
            parent[i] = curr;
            q.push(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, start = 0, end = 0;
    cin >> n >> m;
    string row;
    vector<vector<char>> grid(n, vector<char>(m));
    for (ll i = 0; i < n; i++)
    {
        cin >> row;
        for (ll j = 0; j < m; j++)
        {
            grid[i][j] = row[j];
            if (grid[i][j] == '#')
                continue;
            ll k = i * m + j;
            if (grid[i][j] == 'A')
                start = k;
            if (grid[i][j] == 'B')
                end = k;
            // top and bottom
            if (i >= 1 && grid[i - 1][j] != '#')
            {
                adj[k].push_back(k - m);
                adj[k - m].push_back(k);
            }
            // left and right
            if (j >= 1 && grid[i][j - 1] != '#')
            {
                adj[k - 1].push_back(k);
                adj[k].push_back(k - 1);
            }
        }
    }
    bfs(start);
    if (!vis[end])
    {
        cout << "NO";
        return 0;
    }
    vector<ll> path;
    ll k = end;
    while (k != start)
    {
        path.push_back(k);
        k = parent[k];
    }
    cout << "YES" << endl;
    cout << path.size() << endl;
    string res = "";
    ll i = start / m;
    ll j = start % m;
    for (k = (ll)path.size() - 1; k >= 0; k--)
    {
        ll a = path[k] / m;
        ll b = path[k] % m;
        if (i == a)
        {
            if (b > j)
                res += 'R';
            else
                res += 'L';
        }
        else
        {
            if (a > i)
                res += 'D';
            else
                res += 'U';
        }
        i = a, j = b;
    }
    cout << res;
    return 0;
}
