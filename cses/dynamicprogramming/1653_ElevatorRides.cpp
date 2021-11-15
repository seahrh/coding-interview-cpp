/*
There are n people who want to get to the top of a building which has only one elevator. 
You know the weight of each person and the maximum allowed weight in the elevator. 
What is the minimum number of elevator rides?
Input
The first input line has two integers n and x: the number of people and the maximum allowed weight in the elevator.
The second line has n integers w1,w2,…,wn: the weight of each person.
Output
Print one integer: the minimum number of rides.
Constraints
1≤n≤20
1≤x≤10^9
1≤wi≤x
Example
Input:
4 10
4 8 6 1
Output:
2
SOLUTION
Bitmask dp[mask] = (min rides needed, min weight of people in the last ride)
Go through all people who belong to S and optimally choose the last person i
who enters the elevator. Each such choice yields a subproblem for a smaller
subset of people.

Time O(2^N * N): better than brute force all permutations (N!)
Space O(2^N)

References
- CSES competitive programming handbook p.103
- https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/tutorial/
- https://docs.particle.io/cards/firmware/language-syntax/bitwise-operators/
*/
#include <bits/stdc++.h>
#define ll long long
#define pai tuple<ll, ll>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x;
    cin >> n >> x;
    vector<ll> ws(n);
    for (int i = 0; i < n; i++)
        cin >> ws[i];
    // left bit shift appends n zero bits to the number
    // 1 << n == 2^n
    vector<pai> dp(1 << n);
    // Base case 1: min 1 ride is required!
    dp[0] = {1, 0};
    // s is the subset represented as bit mask
    for (ll s = 1; s < (1 << n); s++)
    {
        // Base case 2: max #rides, empty elevator
        dp[s] = {n, 0};
        for (ll i = 0; i < n; i++)
        {
            // ith person is present in subset
            if (s & (1 << i))
            {
                // get prev computation for subset less ith person
                // caret symbol is bitwise XOR operator
                auto [c, w] = dp[s ^ (1 << i)];
                // reserve new ride for ith person
                if (w + ws[i] > x)
                {
                    c++;
                    w = ws[i];
                }
                else
                    w += ws[i];
                dp[s] = min(dp[s], {c, w});
            }
        }
    }
    cout << get<0>(dp[(1 << n) - 1]);
    return 0;
}
