#include "cses/sortingandsearching/ArrayDivision.hpp"

ll array_division(ll n, ll k, vector<ll> xs)
{
    ll res, j, _sum, mid, lo = xs[0], hi = 0;
    for (ll x : xs)
    {
        lo = max(lo, x);
        hi += x;
    }
    res = hi;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        j = 0;
        _sum = 0;
        for (ll x : xs)
        {
            _sum += x;
            // increment count only if max_sum `mid` is exceeded!
            if (_sum > mid)
            {
                if (++j > k)
                {
                    break;
                }
                _sum = x;
            }
        }
        // add the last subarray!
        if (_sum > 0)
        {
            j++;
        }
        // check if a smaller max_sum is possible
        if (j <= k)
        {
            res = mid;
            hi = mid - 1;
            continue;
        }
        lo = mid + 1;
    }
    return res;
}