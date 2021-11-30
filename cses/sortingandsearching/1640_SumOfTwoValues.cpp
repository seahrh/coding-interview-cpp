/*
You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.
Input
The first input line has two integers n and x: the array size and the target sum.
The second line has n integers a1,a2,…,an: the array values.
Output
Print two integers: the positions of the values. If there are several solutions, you may print any of them.
If there are no solutions, print IMPOSSIBLE.
Constraints
1≤n≤2⋅10^5
1≤x,ai≤10^9
Example
Input:
4 8
2 7 5 1
Output:
2 4
SOLUTION
Sort the array then search for the pair from both ends.
Time O(N lg N)
Space O(N): Requirement to return the positions, hence need to store the positions after sorting.
Otherwise, only O(1) space required.
*/
#include <bits/stdc++.h>
#define pai tuple<int, int>
using namespace std;

optional<tuple<int, int>> solve(int n, int x, vector<int> ar)
{
    vector<pai> sar(n);
    for (int i = 0; i < n; i++)
        // Positions are one-indexed!
        sar[i] = {ar[i], i + 1};
    sort(sar.begin(), sar.end());
    int i = 0, j = n - 1;
    while (i < j)
    {
        int sm = get<0>(sar[i]) + get<0>(sar[j]);
        if (sm == x)
            return make_tuple(get<1>(sar[i]), get<1>(sar[j]));
        if (sm < x)
        {
            i++;
            continue;
        }
        j--;
    }
    return {};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> ar(n);
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    optional<tuple<int, int>> res = solve(n, x, ar);
    if (res)
        cout << get<0>(res.value()) << " " << get<1>(res.value());
    else
        cout << "IMPOSSIBLE";
    return 0;
}
