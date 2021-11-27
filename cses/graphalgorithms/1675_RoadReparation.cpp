/*
There are n cities and m roads between them. 
Unfortunately, the condition of the roads is so poor that they cannot be used. 
Your task is to repair some of the roads so that there will be a decent route between any two cities.
For each road, you know its reparation cost, and you should find a solution where the total cost is as small as possible.
Input
The first input line has two integers n and m: the number of cities and roads. 
The cities are numbered 1,2,…,n.
Then, there are m lines describing the roads. 
Each line has three integers a, b and c: there is a road between cities a and b, and its reparation cost is c. 
All roads are two-way roads.
Every road is between two different cities, and there is at most one road between two cities.
Output
Print one integer: the minimum total reparation cost. However, if there are no solutions, print "IMPOSSIBLE".
Constraints
1≤n≤10^5
1≤m≤2⋅10^5
1≤a,b≤n
1≤c≤10^9
Example
Input:
5 6
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4
Output:
14
SOLUTION
Find minimum spanning tree with Kruskal algorithm and Union-Find.
Time O(E lg E + EV): sort edges by weight, build Union-Find
Space O(V)
References
- https://usaco.guide/gold/mst?lang=cpp
*/
#include <bits/stdc++.h>
#define ll long long
#define tri tuple<ll, ll, ll>
using namespace std;
const ll N = 1e5 + 1;
// par[i] = parent node of i in the same connected component
// if par[i] == 0, then i is the root of the cc
vector<ll> par(N);
// len[i] = size of cc rooted at node i
vector<ll> len(N, 1);

// find the root of the connected component tree
ll find(ll s)
{
    while (par[s] != 0)
        s = par[s];
    return s;
}

void uni(ll x, ll y)
{
    // smaller cc always on the left
    if (len[x] > len[y])
        swap(x, y);
    // add smaller cc to larger cc
    par[x] = y;
    len[y] += len[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, a, b, w;
    cin >> n >> m;
    vector<tri> es;
    while (m--)
    {
        cin >> a >> b >> w;
        es.push_back({w, a, b});
    }
    sort(es.begin(), es.end());
    // number of connected components
    ll nc = n;
    ll c = 0;
    for (auto [w, a, b] : es)
    {
        ll x = find(a), y = find(b);
        if (x == y)
            continue;
        c += w;
        uni(x, y);
        nc--;
    }
    if (nc == 1)
        cout << c;
    else
        cout << "IMPOSSIBLE";
    return 0;
}