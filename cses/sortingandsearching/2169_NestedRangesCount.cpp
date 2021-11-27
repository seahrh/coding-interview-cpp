/*
Given n ranges, your task is to count for each range how many other ranges it contains and how many other ranges contain it.
Range [a,b] contains range [c,d] if a=c and d=b.
Input
The first input line has an integer n: the number of ranges.
After this, there are n lines that describe the ranges. Each line has two integers x and y: the range is [x,y].
You may assume that no range appears more than once in the input.
Output
First print a line that describes for each range (in the input order) how many other ranges it contains.
Then print a line that describes for each range (in the input order) how many other ranges contain it.
Constraints
1=n=2·10^5
1=x<y=10^9
Example
Input:
4
1 6
2 4
4 8
3 6
Output:
2 0 0 0
0 1 0 1
SOLUTION
Sort ranges by x, y desc so that containing ranges come first.
e.g. (1, 6), (2, 5), (2, 4), (3, 6), (4, 8)
Time O(N lg N)
Space O(N): ranges sorted by y in SortedSet
References
- https://www.youtube.com/watch?v=ORdmSirqrMs
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pai tuple<int, int>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct range
{
    int x, y, index;
    bool operator<(const range &other) const
    {
        if (x == other.x)
            return y > other.y;
        return x < other.x;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<range> rs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> rs[i].x >> rs[i].y;
        rs[i].index = i;
    }
    sort(rs.begin(), rs.end());
    // right boundaries (y, index * -1)
    ordered_set<pai> rbs;
    vector<int> res(n);
    // Find number of ranges to the left of curr.y
    // curr.x <= prev.x and prev.y <= curr.y
    for (int i = n - 1; i >= 0; i--)
    {
        pai p = {rs[i].y, -i};
        rbs.insert(p);
        res[rs[i].index] = rbs.order_of_key(p);
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    cout << endl;
    rbs.clear();
    fill(res.begin(), res.begin(), 0);
    // Find number of ranges to the right of curr.y
    // prev.x <= curr.x and curr.y <= prev.y
    for (int i = 0; i < n; i++)
    {
        pai p = {rs[i].y, -i};
        rbs.insert(p);
        res[rs[i].index] = (int)rbs.size() - rbs.order_of_key(p) - 1;
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    return 0;
}