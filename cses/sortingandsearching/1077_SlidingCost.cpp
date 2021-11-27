/*
You are given an array of n integers. 
Your task is to calculate for each window of k elements, from left to right, 
the minimum total cost of making all elements equal.
You can increase or decrease each element with cost x 
where x is the difference between the new and the original value. The total cost is the sum of such costs.
Input
The first input line contains two integers n and k: the number of elements and the size of the window.
Then there are n integers x1,x2,…,xn: the contents of the array.
Output
Output n−k+1 values: the costs.
Constraints
1≤k≤n≤2⋅105
1≤xi≤109
Example
Input:
8 3
2 4 3 5 8 1 2 1
Output:
2 2 5 7 7 1
SOLUTION
Time O(N lg K)
Space O(K)
Middle of two heaps
Invariants
- Lower heap cannot be empty
- Max size of upper heap is size of lower heap
- Max size of lower heap is (size of upper heap + 1)
Regardless of even or odd window length, median is always the largest item in lower heap.
In C++, use `multiset` (BSTs) for upper and lower heaps.
References
- https://www.youtube.com/watch?v=rMK_or9QNrg
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
multiset<ll> up;
multiset<ll> lo;
ll sup = 0, slo = 0;

void add(ll val)
{
    if (lo.empty())
    {
        lo.insert(val);
        slo += val;
        return;
    }
    ll median = *lo.rbegin();
    if (val > median)
    {
        up.insert(val);
        sup += val;
        // move smallest item from upper to lower
        if ((ll)up.size() > (ll)lo.size())
        {
            ll z = *up.begin();
            lo.insert(z);
            up.erase(up.begin());
            sup -= z, slo += z;
        }
    }
    else
    {
        lo.insert(val);
        slo += val;
        // move largest item from lower to upper
        if ((ll)lo.size() > (ll)up.size() + 1)
        {
            ll z = *lo.rbegin();
            up.insert(z);
            // erase(lo.rbegin()) does not compile!
            // see https://stackoverflow.com/questions/8992658/multiset-erase-last-element
            lo.erase(--lo.end());
            slo -= z, sup += z;
        }
    }
}

void remove(ll val)
{
    // find gets the first equivalent item
    auto it = up.find(val);
    if (it != up.end())
    {
        sup -= *it;
        up.erase(it);
        return;
    }
    it = lo.find(val);
    slo -= *it;
    lo.erase(it);
    if (lo.empty())
    {
        ll z = *up.begin();
        lo.insert(z);
        up.erase(up.begin());
        sup -= z, slo += z;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<ll> xs(n);
    for (ll i = 0; i < n; i++)
        cin >> xs[i];
    // Corner cases k=1, k=2
    if (k == 1)
    {
        for (ll i = 0; i < n; i++)
            cout << 0 << " ";
        return 0;
    }
    if (k == 2)
    {
        for (ll i = 1; i < n; i++)
            cout << abs(xs[i] - xs[i - 1]) << " ";
        return 0;
    }
    for (ll i = 0; i < n; i++)
    {
        add(xs[i]);
        if ((ll)up.size() + (ll)lo.size() == k)
        {
            ll md = *lo.rbegin();
            ll c1 = (ll)lo.size() * md - slo;
            ll c2 = sup - (ll)up.size() * md;
            cout << c1 + c2 << " ";
            remove(xs[i - k + 1]);
        }
    }
    return 0;
}