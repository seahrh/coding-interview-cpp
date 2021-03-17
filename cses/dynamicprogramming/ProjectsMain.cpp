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
Two choices: either do project i or give it up (same as dp[i - 1]).
Do project i = reward(i) + dp[j]
where j is the nearest project on the left that ends before the start date of project i.
Time O(N lg N): sort projects, binary search in the loop
Space O(N): memo array
See https://www.youtube.com/watch?v=MJn3ogwsUbo
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool ordering(const tuple<ll, ll, ll> &l, const tuple<ll, ll, ll> &r)
{
    return (get<1>(l) < get<1>(r));
}

ll solve(int n, vector<tuple<ll, ll, ll>> ar)
{
    sort(ar.begin(), ar.end(), ordering);
    vector<ll> dp(n + 1, 0);
    // cannot init dp[1] because projects are sorted only by end-time (not reward)!
    for (int i = 1; i <= n; i++)
    {
        ll take = get<2>(ar[i - 1]);
        ll start = get<0>(ar[i - 1]);
        auto it = lower_bound(ar.begin(), ar.end(), make_tuple(1, start, 1), ordering);
        // minus 1 to get the first project on the left that ends before curr start-time
        // add 1 because dp array starts from index 1
        // so -1 and +1 cancel each out
        int j = distance(ar.begin(), it);
        if (j >= 0)
        {
            take += dp[j];
        }
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
    vector<tuple<ll, ll, ll>> ar(n);
    ll a, b, p;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> p;
        ar[i] = make_tuple(a, b, p);
    }
    cout << solve(n, ar);
    return 0;
}
