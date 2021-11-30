/*
You are given an array of n integers, and your task is to find four values (at distinct positions) whose sum is x.
Input
The first input line has two integers n and x: the array size and the target sum.
The second line has n integers a1,a2,…,an: the array values.
Output
Print four integers: the positions of the values. 
If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.
Constraints
1≤n≤1000
1≤x,ai≤10^9
Example
Input:
8 15
3 2 5 8 1 3 2 3
Output:
2 4 6 7
SOLUTION
Break down the sum x = a + b + c + d into sum of two pairs.
1st pass
- Get first pair sum by looping all combinations
- Not permutations because sum is associative
2nd pass
- Find the 2nd pair (complement of the 1st pair sum)

Time O(N^2)
Space O(N^2): bec we have to store positions, otherwise O(1).

References
- https://usaco.guide/problems/cses-1642-sum-of-four-values/solution
*/
#include <bits/stdc++.h>
#define ll long long
#define pai tuple<ll, ll>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x, sm;
    cin >> n >> x;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    // no need to sort array as we are not doing a bidirectional sweep!
    // Entry (pair sum, positions of i and j)
    map<ll, vector<pai>> ps;
    for (ll i = 0; i < n; i++)
        for (ll j = i + 1; j < n; j++)
        {
            sm = ar[i] + ar[j];
            ps[sm].push_back({i + 1, j + 1});
        }
    for (auto [k, v] : ps)
    {
        // check if another pair has the complement
        ll c = x - k;
        if (ps.find(c) == ps.end())
            continue;
        for (auto [i, j] : v)
            for (auto [p, q] : ps[c])
                if (p != i && p != j && q != i && q != j)
                {
                    cout << p << " " << q << " " << i << " " << j;
                    return 0;
                }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
