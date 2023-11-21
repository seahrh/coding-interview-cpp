/*
There is a large hotel, and n customers will arrive soon.
Each customer wants to have a single room.
You know each customer's arrival and departure day.
Two customers can stay in the same room
if the departure day of the first customer is earlier than the arrival day of the second customer.
What is the minimum number of rooms that are needed to accommodate all customers? And how can the rooms be allocated?
Input
The first input line contains an integer n: the number of customers.
Then there are n lines, each of which describes one customer.
Each line has two integers a and b: the arrival and departure day.
Output
Print first an integer k: the minimum number of rooms required.
After that, print a line that contains the room number of each customer in the same order as in the input.
The rooms are numbered 1,2,…,k. You can print any valid solution.
Constraints
1≤n≤2⋅10^5
1≤a≤b≤10^9
Example
Input:
3
1 2
2 4
4 4
Output:
2
1 2 1
SOLUTION
Time O(N lg N): Sort customers by arrival/departure times.
Space O(N): result array, stack to hold empty rooms.
*/
#include <bits/stdc++.h>
#define ll long long
// Sort customers by arrival/departure times.
#define tri tuple<ll, bool, ll>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, a, b;
    cin >> n;
    vector<tri> tim;
    for (ll i = 0; i < n; i++)
    {
        cin >> a >> b;
        tim.push_back({a, 0, i});
        tim.push_back({b, 1, i});
    }
    sort(tim.begin(), tim.end());
    vector<ll> res(n);
    // highest room number unassigned
    ll x = 1;
    // available rooms in a stack
    vector<ll> st;
    for (auto [t, d, i] : tim)
    {
        // departure: return room to stack
        if (d)
        {
            st.push_back(res[i]);
            continue;
        }
        // arrival
        if (st.empty())
            res[i] = x++;
        else
        {
            res[i] = st.back();
            st.pop_back();
        }
    }
    cout << x - 1 << endl;
    for (auto r : res)
        cout << r << " ";
    return 0;
}