/*
You are playing a game consisting of n planets. 
Each planet has a teleporter to another planet (or the planet itself).
Your task is to process q queries of the form: 
when you begin on planet x and travel through k teleporters, which planet will you reach?
Input
The first input line has two integers n and q: the number of planets and queries. 
The planets are numbered 1,2,…,n.
The second line has n integers t1,t2,…,tn: for each planet, the destination of the teleporter. 
It is possible that ti=i.
Finally, there are q lines describing the queries. 
Each line has two integers x and k: you start on planet x and travel through k teleporters.
Output
Print the answer to each query.
Constraints
1=n,q=2·10^5
1=ti=n
1=x=n
0=k=10^9
Example
Input:
4 3
2 1 1 4
1 2
3 4
4 1
Output:
1
2
4
SOLUTION
Binary lifting to find destination k hops away (bottom-up DP)
dp[i][j] = (j^2)th hops from node i 
Jumps are in powers of 2 starting from 1,2,4, ...
Recurrence: dp[i][j] = dp[ dp[i][j - 1] ][j - 1]

Building the dp table:
Time O(N lg K)
Space O(N lg K)
Each query takes O(lg K) time.

References
- https://iq.opengenus.org/binary-lifting-k-th-ancestor-lowest-common-ancestor/
- https://usaco.guide/plat/binary-jump?lang=cpp
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 2e5;
const ll maxk = (ll)log2(1e9) + 1;
vector<vector<ll>> dp(maxn + 1, vector<ll>(maxk + 1));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q, x, k;
    cin >> n >> q;
    for (ll i = 1; i < n + 1; i++)
        cin >> dp[i][0];
    // Recurrence requires k to be the outer loop
    for (k = 1; k < maxk + 1; k++)
        for (ll i = 1; i < n + 1; i++)
            dp[i][k] = dp[dp[i][k - 1]][k - 1];
    while (q--)
    {
        cin >> x >> k;
        while (k > 0)
        {
            ll z = (ll)log2(k);
            x = dp[x][z];
            k -= (ll)pow(2, z);
        }
        cout << x << endl;
    }
    return 0;
}