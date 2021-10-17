/*
You are given the arrival and leaving times of n customers in a restaurant.
What was the maximum number of customers?
Input
The first input line has an integer n: the number of customers.
After this, there are n lines that describe the customers.
Each line has two integers a and b: the arrival and leaving times of a customer.
You may assume that all arrival and leaving times are distinct.
Output
Print one integer: the maximum number of customers.
Constraints
1<= n <= 2·10^5
1<= a<b <=10^9
Example
Input:
3
5 8
2 4
3 9
Output:
2
SOLUTION
Put all arrival and departures in a "timeline" array, then sort the array.
Increment the count when it is an arrival, else decrement.
Time O(N lg N)
Space O(N)
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<tuple<int, int>> customers)
{
    int res, curr = 0;
    int a, b;
    bool is_arrival;
    vector<tuple<int, bool>> timeline;
    for (int i = 0; i < n; i++)
    {
        a = get<0>(customers[i]);
        b = get<1>(customers[i]);
        timeline.push_back(make_tuple(a, true));
        timeline.push_back(make_tuple(b, false));
    }
    sort(timeline.begin(), timeline.end());
    for (int i = 0; i < n * 2; i++)
    {
        is_arrival = get<1>(timeline[i]);
        if (is_arrival)
        {
            curr++;
        }
        else
        {
            curr--;
        }
        res = max(curr, res);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b;
    cin >> n;
    vector<tuple<int, int>> customers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        customers[i] = make_tuple(a, b);
    }
    cout << solve(n, customers) << endl;
    return 0;
}