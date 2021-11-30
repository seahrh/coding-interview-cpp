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
dp[i] = #subordinates of employee i
Time O(N)
Space O(N): each employee can have at most one boss
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll N = 2e5;
// no need to mark visited bec no cycles
vector<vector<ll>> adj(N + 1);
vector<ll> dp(N + 1);

void dfs(ll s)
{
    for (auto i : adj[s])
    {
        dfs(i);
        dp[s] += dp[i] + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x;
    cin >> n;
    for (ll i = 2; i < n + 1; i++)
    {
        cin >> x;
        // i is a subordinate of x
        adj[x].push_back(i);
    }
    dfs(1);
    for (ll i = 1; i < n + 1; i++)
        cout << dp[i] << " ";
    return 0;
}