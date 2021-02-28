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
Requirement: Sell the most expensive ticket that meets the customer's budget
Time O((N + M) lg N)
Space O(N): store the ticket prices in a SortedSet.
*/

#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
#define ar array
using namespace std;
const lli mod = 1e9 + 7;

std::vector<lli> solve(std::vector<lli> tickets, std::vector<lli> customers)
{
    std::vector<lli> res;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n, m, customer, ticket;
    cin >> n >> m;
    std::vector<lli> tickets;
    std::vector<lli> customers;
    while (n--)
    {
        cin >> ticket;
        tickets.push_back(ticket);
    }
    while (m--)
    {
        cin >> customer;
        customers.push_back(customer);
    }
    std::vector<lli> res = solve(tickets, customers);
    for (auto r = begin(res); r != end(res); ++r)
    {
        cout << *r << endl;
    }
    return 0;
}