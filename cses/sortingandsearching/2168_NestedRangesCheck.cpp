/*
Given n ranges, your task is to determine for each range 
if it contains some other range and if some other range contains it.
Range [a,b] contains range [c,d] if a≤c and d≤b.
Input
The first input line has an integer n: the number of ranges.
After this, there are n lines that describe the ranges. 
Each line has two integers x and y: the range is [x,y].
You may assume that no range appears more than once in the input.
Output
First print a line that describes for each range (in the input order) if it contains some other range (1) or not (0).
Then print a line that describes for each range (in the input order) if some other range contains it (1) or not (0).
Constraints
1≤n≤2⋅10^5
1≤x<y≤10^9
Example
Input:
4
1 6
2 4
4 8
3 6
Output:
1 0 0 0
0 1 0 1
SOLUTION
Sort ranges by x, y desc so that containing ranges come first.
e.g. (1, 6), (2, 5), (2, 4), (3, 6), (4, 8)
Time O(N lg N)
Space O(N): store result array otherwise O(1)
References
- https://www.youtube.com/watch?v=ORdmSirqrMs
*/
#include <bits/stdc++.h>
#define ll long long
#define tri tuple<ll, ll, ll>
using namespace std;
const ll inf = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x, y;
    cin >> n;
    vector<tri> rs;
    for (ll i = 0; i < n; i++)
    {
        cin >> x >> y;
        rs.push_back({x, -y, i});
    }
    sort(rs.begin(), rs.end());
    vector<bool> res(n);
    ll rig = inf;
    for (auto it = rs.rbegin(); it != rs.rend(); ++it)
    {
        auto [x, y, i] = *it;
        y *= -1;
        if (y < rig)
            rig = y;
        else
            // curr range contains prev range
            // curr.x <= prev.x && prev.y <= curr.y 
            res[i] = 1;
    }
    for (ll i = 0; i < n; i++)
        cout << res[i] << " ";
    cout << endl;
    fill(res.begin(), res.end(), 0);
    rig = 0;
    for (auto [x, y, i] : rs)
    {
        y *= -1;
        if (y > rig)
            rig = y;
        else
            // curr range is contained by prev range
            // prev.x <= curr.x && curr.y <= prev.y 
            res[i] = 1;
    }
    for (ll i = 0; i < n; i++)
        cout << res[i] << " ";
    return 0;
}