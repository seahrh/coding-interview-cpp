/*
You are given a map of a building, and your task is to count the number of its rooms.
The size of the map is n×m squares, and each square is either floor or wall.
You can walk left, right, up, and down through the floor squares.
Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the map.
Each character is either . (floor) or # (wall).
Output
Print one integer: the number of rooms.
Constraints
1≤n,m≤1000
Example
Input:
5 8
########
#..#...#
####.#.#
#..#...#
########
Output:
3
SOLUTION
Time O(NM)
Space O(NM)
References
- https://github.com/mrsac7/CSES-Solutions/blob/master/src/1192%20-%20Counting%20Rooms.cpp
- https://japlofficial.github.io/posts/cses/counting_rooms/1.htm
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<bool> vis(1'000'000);
// build adjacency list for floor tiles only
vector<vector<ll>> adj(1'000'000);

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
            // convert grid 2D coordinates to 1D index of adjacency list
            ll k = i * m + j;
            // add edge if top cell is floor
            if (i >= 1 && grid[i - 1][j] == '.')
            {
                adj[k].push_back(k - m);
                adj[k - m].push_back(k);
            }
            // add edge if left cell is floor
            if (j >= 1 && grid[i][j - 1] == '.')
            {
                adj[k - 1].push_back(k);
                adj[k].push_back(k - 1);
            }
        }
    }
    ll res = 0;
    for (ll k = 0; k < n * m; k++)
    {
        ll i = k / m, j = k % m;
        // explore the rest of the room and mark as visited
        if (!vis[k] && grid[i][j] == '.')
        {
            dfs(k);
            res++;
        }
    }
    cout << res;
    return 0;
}
