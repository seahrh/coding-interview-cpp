#include "cses/sortingandsearching/package.hpp"

void add(ll val, multiset<ll> &up, multiset<ll> &lo)
{
    if (lo.empty())
    {
        lo.insert(val);
        return;
    }
    ll median = *lo.rbegin();
    if (val > median)
    {
        up.insert(val);
        // move smallest item from upper to lower
        if ((ll)up.size() > (ll)lo.size())
        {
            lo.insert(*up.begin());
            up.erase(up.begin());
        }
    }
    else
    {
        lo.insert(val);
        // move largest item from lower to upper
        if ((ll)lo.size() > (ll)up.size() + 1)
        {
            up.insert(*lo.rbegin());
            // erase(lo.rbegin()) does not compile!
            // see https://stackoverflow.com/questions/8992658/multiset-erase-last-element
            lo.erase(--lo.end());
        }
    }
}

void remove(ll val, multiset<ll> &up, multiset<ll> &lo)
{
    // find gets the first equivalent item
    auto it = up.find(val);
    if (it != up.end())
    {
        up.erase(it);
        return;
    }
    it = lo.find(val);
    lo.erase(it);
    if (lo.empty())
    {
        lo.insert(*up.begin());
        up.erase(up.begin());
    }
}

vector<ll> sliding_median(ll n, ll k, vector<ll> xs)
{
    vector<ll> res;
    multiset<ll> up;
    multiset<ll> lo;
    for (ll i = 0; i < n; i++)
    {
        if (k == 1)
        {
            res.push_back(xs[i]);
            continue;
        }
        add(xs[i], up, lo);
        if ((ll)up.size() + (ll)lo.size() == k)
        {
            res.push_back(*lo.rbegin());
            remove(xs[i - k + 1], up, lo);
        }
    }
    return res;
}