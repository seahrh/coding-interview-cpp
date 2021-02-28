#include "cses/sortingandsearching/ConcertTickets.hpp"

vector<lli> solve(vector<lli> tickets, vector<lli> customers)
{
    vector<lli> res;
    multiset<lli, greater<int>> sortedTickets;
    for (auto t = begin(tickets); t != end(tickets); ++t)
    {
        sortedTickets.insert(*t);
    }
    for (auto c = begin(customers); c != end(customers); ++c)
    {
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