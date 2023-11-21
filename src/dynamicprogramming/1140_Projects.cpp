/*
There are n projects you can attend.
For each project, you know its starting and ending days and the amount of money you would get as reward.
You can only attend one project during a day.
What is the maximum amount of money you can earn?
Input
The first input line contains an integer n: the number of projects. After this, there are n lines.
Each line has three integers ai, bi, and pi: the starting day, the ending day, and the reward.
Output
Print one integer: the maximum amount of money you can earn.
Constraints
1≤n≤2⋅10^5
1≤ai≤bi≤10^9
1≤pi≤10^9
Example
Input:
4
2 4 4
3 6 6
6 8 2
5 7 3
Output:
7
SOLUTION
Bottom-up DP, dp[i] = max reward for considering the first i projects
Two choices: either do project i or give it up
Recurring relation: dp[i] = max(dp[i - 1], take project i)
Take project i = reward_i + dp[j]
where j is the nearest project on the left that ends before the start date of project i.
Time O(N lg N): sort projects, binary search in the loop
Space O(N): memo array
See https://www.youtube.com/watch?v=MJn3ogwsUbo
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// sort by end-time
bool ordering(const tuple<ll, ll, ll> &a, const tuple<ll, ll, ll> &b)
{
    return (get<1>(a) < get<1>(b));
}

ll solve(int n, vector<tuple<ll, ll, ll>> ps)
{
    sort(ps.begin(), ps.end(), ordering);
    vector<ll> dp(n + 1);
    // Base case: dp[0] = 0
    // cannot set dp[1] = reward of first project
    // because projects are sorted by end-time (not reward)!
    // start dp loop from index 1
    // so ith project is actually (i - 1)
    for (int i = 1; i < n + 1; i++)
    {
        ll take = get<2>(ps[i - 1]);
        ll start = get<0>(ps[i - 1]);
        // first project that ends on or after start date of project i
        // (i.e. first project that conflicts with project i)
        auto it = lower_bound(ps.begin(), ps.end(), make_tuple(1, start, 1), ordering);
        int j = distance(ps.begin(), it);
        // say j=2, so we should consider only ps[0] and ps[1] (but not ps[2]!)
        // therefore use dp[2] (first two projects)
        if (j >= 0)
            take += dp[j];
        dp[i] = max(dp[i - 1], take);
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<tuple<ll, ll, ll>> ps(n);
    ll a, b, p;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> p;
        ps[i] = make_tuple(a, b, p);
    }
    cout << solve(n, ps);
    return 0;
}
