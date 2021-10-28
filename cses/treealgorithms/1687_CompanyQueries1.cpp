/*
A company has n employees, who form a tree hierarchy 
where each employee has a boss, except for the general director.
Your task is to process q queries of the form: 
who is employee x's boss k levels higher up in the hierarchy?
Input
The first input line has two integers n and q: the number of employees and queries. 
The employees are numbered 1,2,…,n, and employee 1 is the general director.
The next line has n−1 integers e2,e3,…,en: for each employee 2,3,…,n their boss.
Finally, there are q lines describing the queries. 
Each line has two integers x and k: who is employee x's boss k levels higher up?
Output
Print the answer for each query. If such a boss does not exist, print −1.
Constraints
1≤n,q≤2⋅10^5
1≤ei≤i−1
1≤x≤n
1≤k≤n
Example
Input:
5 3
1 1 3 3
4 1
4 2
4 3
Output:
3
1
-1
SOLUTION
Binary lifting with k-th ancestor (bottom-up DP)
dp[i][j] = (j^2)th ancestor of node i 
Jumps are in powers of 2 starting from 1,2,4, ...
Recurrence: dp[i][j] = dp[ dp[i][j - 1] ][j - 1]

Building the dp table:
Time O(N lg N)
Space O(N lg N)
Each query takes O(lg N) time.

References
- https://iq.opengenus.org/binary-lifting-k-th-ancestor-lowest-common-ancestor/
- https://usaco.guide/plat/binary-jump?lang=cpp
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll maxn = 2e5 + 1;
ll maxk = (ll)log2(maxn) + 1;
vector<vector<ll>> dp(maxn, vector<ll>(maxk));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q, x, k;
    cin >> n >> q;
    // Base case: immediate ancestors
    for (int i = 2; i < n + 1; i++)
    {
        cin >> x;
        dp[i][0] = x;
    }
    for (ll i = 2; i < n + 1; i++)
        for (ll j = 1; j < maxk + 1; j++)
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
    while (q--)
    {
        cin >> x >> k;
        // reduce distance to zero
        while (k > 0)
        {
            ll z = (ll)log2(k);
            // update curr to ancestor node
            x = dp[x][z];
            k -= (ll)pow(2, z);
        }
        ll res = -1;
        if (x > 0)
            res = x;
        cout << res << endl;
    }
    return 0;
}
