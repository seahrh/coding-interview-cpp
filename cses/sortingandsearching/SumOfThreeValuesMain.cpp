/*
You are given an array of n integers, and your task is to find three values (at distinct positions) whose sum is x.
Input
The first input line has two integers n and x: the array size and the target sum.
The second line has n integers a1,a2,…,an: the array values.
Output
Print three integers: the positions of the values.
If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.
Constraints
1=n=5000
1=x,ai=10^9      Be careful of data type for x (int will suffice; long long not required!)
Example
Input:
4 8
2 7 5 1
Output:
1 3 4
SOLUTION
Sort the array and run through all indices of a possible first element of a triplet.
For each possible first element, make a bi-directional sweep of the remaining part of the array.
Time O(N^2)
Space O(N): Requirement to return the positions, hence need to store the positions after sorting.
Otherwise, only O(1) space required.
*/
#include <bits/stdc++.h>
using namespace std;

optional<tuple<int, int, int>> solve(int n, int x, vector<int> ar)
{
    vector<tuple<int, int>> sar(n);
    for (int i = 0; i < n; i++)
    {
        // positions are one-indexed!
        sar[i] = make_tuple(ar[i], i + 1);
    }
    sort(sar.begin(), sar.end());
    int _sum, i, j, k;
    // maintain two slots ahead for j and k
    for (i = 0; i < n - 2; i++)
    {
        j = i + 1;
        k = n - 1;
        while (j < k)
        {
            _sum = get<0>(sar[i]) + get<0>(sar[j]) + get<0>(sar[k]);
            if (_sum == x)
            {
                return make_tuple(get<1>(sar[i]), get<1>(sar[j]), get<1>(sar[k]));
            }
            if (_sum < x)
            {
                j++;
                continue;
            }
            k--;
        }
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
    {
        cin >> ar[i];
    }
    optional<tuple<int, int, int>> res = solve(n, x, ar);
    tuple<int, int, int> t;
    if (res)
    {
        t = res.value();
        cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t);
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
    return 0;
}
