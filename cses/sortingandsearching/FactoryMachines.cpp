#include "cses/sortingandsearching/FactoryMachines.hpp"

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