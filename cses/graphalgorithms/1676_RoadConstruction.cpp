/*
There are n cities and initially no roads between them. 
However, every day a new road will be constructed, and there will be a total of m roads.
A component is a group of cities where there is a route between any two cities using the roads. 
After each day, your task is to find the number of components and the size of the largest component.
Input
The first input line has two integers n and m: the number of cities and roads. 
The cities are numbered 1,2,…,n.
Then, there are m lines describing the new roads. 
Each line has two integers a and b: a new road is constructed between cities a and b.
You may assume that every road will be constructed between two different cities.
Output
Print m lines: the required information after each day.
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
4 2
3 3
2 3
SOLUTION
Union-Find
Time O(EV)
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 1e5 + 1;
// par[i] = parent node of i in the same connected component
// if par[i] == 0, then i is the root of the cc
vector<ll> par(maxn);
// len[i] = size of cc rooted at node i
vector<ll> len(maxn, 1);

// find the root of the connected component tree
ll find(ll s)
{
    while (par[s] != 0)
        s = par[s];
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, a, b, c, mx;
    cin >> n >> m;
    c = n, mx = 1;
    while (m--)
    {
        cin >> a >> b;
        ll x = find(a), y = find(b);
        if (x != y)
        {
            // smaller cc always on the left
            if (len[x] > len[y])
                swap(x, y);
            // add smaller cc to larger cc
            par[x] = y;
            len[y] += len[x];
            c--;
            mx = max(mx, len[y]);
        }
        cout << c << " " << mx << endl;
    }

    return 0;
}