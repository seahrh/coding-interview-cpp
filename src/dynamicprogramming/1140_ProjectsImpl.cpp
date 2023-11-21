#include "src/dynamicprogramming/package.hpp"

bool ordering(const tuple<ll, ll, ll> &l, const tuple<ll, ll, ll> &r)
{
    return (get<1>(l) < get<1>(r));
}

ll projects(int n, vector<tuple<ll, ll, ll>> ar)
{
    sort(ar.begin(), ar.end(), ordering);
    vector<ll> dp(n + 1, 0);
    // cannot init dp[1] because projects are sorted only by end-time (not reward)!
    for (int i = 1; i <= n; i++)
    {
        ll take = get<2>(ar[i - 1]);
        ll start = get<0>(ar[i - 1]);
        auto it = lower_bound(ar.begin(), ar.end(), make_tuple(1, start, 1), ordering);
        // minus 1 to get the first project on the left that ends before curr start-time
        // add 1 because dp array starts from index 1
        // so -1 and +1 cancel each out
        int j = distance(ar.begin(), it);
        if (j >= 0)
        {
            take += dp[j];
        }
        dp[i] = max(dp[i - 1], take);
        /*
        printf("i=%d, j=%d, take=%ld\n", i, j, take);
        for (int k = 0; k <= n; k++)
        {
            printf("dp[%d]=%ld,", k, dp[k]);
        }
        printf("\n");
        */
    }
    return dp[n];
}
