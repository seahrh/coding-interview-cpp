/*
Your task is to divide the numbers 1,2,…,n into two sets of equal sum.
Input
The only input line contains an integer n.
Output
Print "YES", if the division is possible, and "NO" otherwise.
After this, if the division is possible, print an example of how to create the sets.
First, print the number of elements in the first set followed by the elements themselves in a separate line,
and then, print the second set in a similar way.
Constraints
1≤n≤10^6
Example 1
Input:
7
Output:
YES
4
1 2 4 7
3
3 5 6
Example 2
Input:
6
Output:
NO
SOLUTION
There must be a solution if the sum is even (no solution if the sum is odd).
The "budget" for each subset is half of the sum. Loop N..1 to partition the set.
If the budget of the first subset is not enough to cover the current number, add it to the other subset.
Time O(N)
Space O(N): store the output, else O(1) if just printing the result
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

optional<tuple<vector<ll>, vector<ll>>> solve(ll n)
{
    // triangular number
    ll _sum = n * (n + 1) / 2;
    if (_sum % 2 == 1)
    {
        return {};
    }
    ll budget = _sum / 2;
    vector<ll> left, right;
    for (ll i = n; i > 0; i--)
    {
        if (budget - i >= 0)
        {
            left.push_back(i);
            budget -= i;
        }
        else
        {
            right.push_back(i);
        }
    }
    return make_tuple(left, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    optional<tuple<vector<ll>, vector<ll>>> res = solve(n);
    if (res)
    {
        cout << "YES\n";
        vector<ll> ar = get<0>(res.value());
        cout << ar.size() << "\n";
        for (ll r : ar)
        {
            cout << r << " ";
        }
        cout << "\n";
        ar = get<1>(res.value());
        cout << ar.size() << "\n";
        for (ll r : ar)
        {
            cout << r << " ";
        }
    }
    else
    {
        cout << "NO";
    }
    return 0;
}