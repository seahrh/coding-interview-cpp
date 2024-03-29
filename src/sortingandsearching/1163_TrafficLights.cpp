/*
There is a street of length x whose positions are numbered 0,1,…,x.
Initially there are no traffic lights, but n sets of traffic lights are added to the street one after another.
Your task is to calculate the length of the longest passage without traffic lights after each addition.
Input
The first input line contains two integers x and n:
the length of the street and the number of sets of traffic lights.
Then, the next line contains n integers p1,p2,…,pn: the position of each set of traffic lights.
Each position is distinct.
Output
Print the length of the longest passage without traffic lights after each addition.
Constraints
1≤x≤10^9
1≤n≤2⋅10^5
0<pi<x
Example
Input:
8 3
3 6 2
Output:
5 3 3
SOLUTION
Suppose a traffic light is placed in the middle of a segment of length 30.
Then delete '30' and insert two '15's.
Time O(N lg N): Binary search in a loop
Space O(N)
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int x, int n, vector<int> ps)
{
    // Ensure there must be a left and right ("fake" traffic lights if you will)
    set<int> positions = {0, x};
    // Max length = x - 0
    multiset<int> lengths = {x};
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        // pointer to the first greater element
        auto it = positions.upper_bound(ps[i]);
        // [left, right] is the range in which the point is being inserted
        int left = *prev(it);
        int right = *it;
        // remove that range from lengths, then add new
        lengths.erase(lengths.find(right - left));
        lengths.insert(ps[i] - left);
        lengths.insert(right - ps[i]);
        positions.insert(it, ps[i]);
        // max length
        res[i] = *lengths.rbegin();
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, n;
    cin >> x >> n;
    vector<int> ps(n);
    for (int i = 0; i < n; i++)
        cin >> ps[i];
    vector<int> res = solve(x, n, ps);
    for (auto it = res.begin(); it != res.end(); ++it)
        cout << *it << " ";
    return 0;
}
