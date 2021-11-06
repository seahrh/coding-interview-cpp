/*
You are playing a game consisting of n planets. 
Each planet has a teleporter to another planet (or the planet itself).
You start on a planet and then travel through teleporters until you reach a planet that you have already visited before.
Your task is to calculate for each planet the number of teleportations there would be if you started on that planet.
Input
The first input line has an integer n: the number of planets. 
The planets are numbered 1,2,…,n.
The second line has n integers t1,t2,…,tn: for each planet, the destination of the teleporter. 
It is possible that ti=i.
Output
Print n integers according to the problem statement.
Constraints
1≤n≤2⋅10^5
1≤ti≤n
Example
Input:
5
2 4 3 1 4
Output:
3 3 1 3 4
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 2e5;
// suc[i] = successor of node i
vector<ll> suc(maxn + 1);
// len[i] = #hops to reach a twice-visited node ("repeat node") from node i 
vector<ll> len(maxn + 1);
vector<bool> vis(maxn + 1);
vector<ll> path;

void dfs(ll s)
{
    path.push_back(s);
    vis[s] = 1;
    ll tail = suc[s];
    while (!vis[tail])
    {
        vis[tail] = 1;
        path.push_back(tail);
        tail = suc[tail];
    }
    ll h;
    // Cycle found; number of hops from tail is already known
    if (len[tail])
        h = len[tail];
    else
    {
        // Get the nodes of this cycle
        // All nodes in the cycle need the same number of hops to come back to self!
        vector<ll> cyc = {tail};
        ll head = path.back();
        path.pop_back();
        while (!path.empty() && head != tail)
        {
            cyc.push_back(head);
            head = path.back();
            path.pop_back();
        }
        // no need to add head to cycle
        // because number of hops starts from head node
        h = (ll)cyc.size();
        for (auto i : cyc)
            len[i] = h;
    }
    // Backtrack path to extend the length of cycle
    while (!path.empty())
    {
        tail = path.back();
        path.pop_back();
        len[tail] = ++h;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    for (ll i = 1; i < n + 1; i++)
        cin >> suc[i];
    for (ll i = 1; i < n + 1; i++)
        if (!vis[i])
            dfs(i);
    for (ll i = 1; i < n + 1; i++)
        cout << len[i] << " ";
    return 0;
}
