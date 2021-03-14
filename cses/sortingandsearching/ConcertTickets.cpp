#include "cses/sortingandsearching/package.hpp"

vector<ll> concert_tickets(vector<ll> tickets, vector<ll> customers)
{
    vector<ll> res;
    // sort price in descending order!
    multiset<ll, greater<int>> sortedTickets;
    for (auto t = begin(tickets); t != end(tickets); ++t)
    {
        sortedTickets.insert(*t);
    }
    for (auto c = begin(customers); c != end(customers); ++c)
    {
        // get first ticket that equals budget
        // else get next ticket that is below budget
        auto t = sortedTickets.lower_bound(*c);
        if (t == sortedTickets.end())
        {
            res.push_back(-1);
            continue;
        }
        res.push_back(*t);
        sortedTickets.erase(t);
    }
    return res;
}