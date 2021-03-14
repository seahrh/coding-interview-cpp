/*
A factory has n machines which can be used to make products. Your goal is to make a total of t products.
For each machine, you know the number of seconds it needs to make a single product.
The machines can work simultaneously, and you can freely decide their schedule.
What is the shortest time needed to make t products?
Input
The first input line has two integers n and t: the number of machines and products.
The next line has n integers k1,k2,…,kn: the time needed to make a product using each machine.
Output
Print one integer: the minimum time needed to make t products.
Constraints
1≤n≤2⋅10^5
1≤t≤10^9
1≤ki≤10^9
Example
Input:
3 7
3 2 5
Output:
8
Explanation: Machine 1 makes two products, machine 2 makes four products and machine 3 makes one product.
SOLUTION
Observe that it's optimal for every machine to work simultaneously.
Then, in `res` time, machine i can create (res / ki) products.
Binary search on solution space i.e. time range [1, t * k_max].
Time O(N lg T)
Space O(1)

See https://usaco.guide/solutions/cses-1620?lang=cpp
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll n, ll t, vector<ll> ks)
{
    ll k_max = *max_element(ks.begin(), ks.end());
    ll lo = 1;
    ll hi = t * k_max;
    ll res = hi;
    ll mid, _sum;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        _sum = 0;
        for (ll k : ks)
        {
            _sum += (mid / k);
            // deal with overflow
            if (_sum >= t)
            {
                break;
            }
        }
        if (_sum >= t)
        {
            res = mid;
            hi = mid - 1;
            continue;
        }
        lo = mid + 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, t;
    cin >> n >> t;
    vector<ll> ks(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ks[i];
    }
    cout << solve(n, t, ks);
    return 0;
}
