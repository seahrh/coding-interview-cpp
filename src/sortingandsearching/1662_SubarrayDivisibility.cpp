/*
Given an array of n integers, count the number of subarrays where the sum of values is divisible by n.
Input
The first input line has an integer n: the size of the array.
The next line has n integers a1,a2,…,an: the contents of the array.
Output
Print one integer: the required number of subarrays.
Constraints
1≤n≤2⋅10^5
−10^9≤ai≤10^9
Example
Input:
5
3 1 2 7 4
Output:
1
SOLUTION
Do a prefix sum from left to right.
There exists a subarray divisible by N if the same remainder R is encountered twice or more
(i.e. completed at least one full cycle of N and therefore divisible by N)
subarray S1 = (P*N)+R
subarray S2 = (Q*N)+R
S2 - S1 = N*(Q-P)
N choose 2: how pairs of subarrays can be combined to form a longer subarray
NC2 = N! / (R! * (N - R)!) = N(N - 1)/2
Time O(N)
Space O(N): store the counts of remainders
References
- https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/hashmap-and-heaps/count_of_subarrays_with_sum_divisible_by_k/topic
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(int n, vector<ll> ar)
{
    ll res = 0, sm = 0;
    // Map remainder to count of prefix subarrays
    vector<ll> counts(n, 0);
    for (ll a : ar)
    {
        sm += a;
        // Take modulus twice as sum can be negative!
        counts[(sm % n + n) % n] += 1;
    }
    for (ll c : counts)
    {
        if (c > 1)
        {
            // N choose 2
            res += (ll)c * (c - 1) / 2;
        }
    }
    res += counts[0];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    cout << solve(n, ar);
    return 0;
}
