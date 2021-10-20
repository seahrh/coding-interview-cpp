/*
Given the structure of a company, your task is to calculate for each employee the number of their subordinates.
Input
The first input line has an integer n: the number of employees.
The employees are numbered 1,2,…,n, and employee 1 is the general director of the company.
After this, there are n−1 integers: for each employee 2,3,…,n their direct boss in the company.
Output
Print n integers: for each employee 1,2,…,n the number of their subordinates.
Constraints
1≤n≤2⋅10^5
Example
Input:
5
1 1 2 3
Output:
4 1 1 0 0
SOLUTION
Directed acyclic graph where edge represents "SubordinateOf". 
Root is biggest boss in the company.
Time O(N)
Space O(N): each employee can have at most one boss
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll max_size = (ll)2e5;
// no need to mark visited because traversing from root
vector<vector<ll>> adj(max_size);
vector<ll> sb(max_size);

void dfs(ll s)
{
    for (auto i : adj[s])
    {
        dfs(i);
        sb[s] += sb[i] + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x;
    cin >> n;
    for (ll i = 1; i < n; i++)
    {
        cin >> x;
        // i is a subordinate of (x-1)
        adj[x - 1].push_back(i);
    }
    dfs(0);
    for (ll i = 0; i < n; i++)
    {
        cout << sb[i] << " ";
    }
    return 0;
}