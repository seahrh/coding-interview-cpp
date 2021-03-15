/*
There are n apples with known weights.
Divide the apples into two groups so that the difference between the weights of the groups is minimal.
Input
The first input line has an integer n: the number of apples.
The next line has n integers p1,p2,…,pn: the weight of each apple.
Output
Print one integer: the minimum difference between the weights of the groups.
Constraints
1≤n≤20
1≤pi≤10^9
Example
Input:
5
3 2 7 4 1
Output:
1
Explanation: Group 1 has weights 2, 3 and 4 (total weight 9), and group 2 has weights 1 and 7 (total weight 8).
SOLUTION
Membership of the best groups do not follow a sorted ordering, so sorting doesn't help.
Backtracking brute force without pruning; either add current apple to first group or not.
Time O(2^N)
Space O(N): depth of recursive call stack
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll _solve(int n, vector<ll> ps, int index, ll first_sum, ll second_sum, ll best)
{
    // Backtracking function must return the best value
    // because the `best` argument is an immutable integer (hence pass by value)
    if (index == n)
    {
        return min(best, abs(first_sum - second_sum));
    }
    // compare best scores from the left and right subtrees of the recursion tree
    ll res = _solve(n, ps, index + 1, first_sum + ps[index], second_sum, best);
    res = _solve(n, ps, index + 1, first_sum, second_sum + ps[index], res);
    return res;
}

ll solve(int n, vector<ll> ps)
{
    return _solve(n, ps, 0, 0, 0, 1e9);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> ps(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ps[i];
    }
    cout << solve(n, ps);
    return 0;
}
