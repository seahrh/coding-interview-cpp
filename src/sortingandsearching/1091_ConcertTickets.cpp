/*
There are n concert tickets available, each with a certain price.
Then, m customers arrive, **one after another**.
Each customer announces the maximum price he or she is willing to pay for a ticket,
and after this, they will get a ticket with the **nearest possible price**
such that it does not exceed the maximum price.
Input
The first input line contains integers n and m: the number of tickets and the number of customers.
The next line contains n integers h1,h2,…,hn: the price of each ticket.
The last line contains m integers t1,t2,…,tm: the maximum price for each customer.
Output
Print, for each customer, the price that they will pay for their ticket.
After this, the ticket cannot be purchased again.
If a customer cannot get any ticket, print −1.
Constraints
1≤n,m≤2⋅10^5
1≤hi,ti≤10^9
Example
Input:
5 3
5 3 7 8 5
4 8 3
Output:
3
8
-1
See https://cses.fi/problemset/task/1091
SOLUTION
Sell the most expensive ticket that customer can afford.
Time O((N + M) lg N)
Space O(N): store ticket prices in a SortedList (multiset)
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, i, x;
    cin >> n >> m;
    // sort tickets by price in descending order!
    multiset<ll, greater<ll>> bst;
    vector<ll> customers;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        bst.insert(x);
    }
    for (i = 0; i < m; i++)
    {
        cin >> x;
        customers.push_back(x);
    }
    for (auto c : customers)
    {
        ll res = -1;
        // the most expensive ticket that customer can afford
        auto t = bst.lower_bound(c);
        if (t != bst.end())
        {
            res = *t;
            bst.erase(t);
        }
        cout << res << endl;
    }
    return 0;
}