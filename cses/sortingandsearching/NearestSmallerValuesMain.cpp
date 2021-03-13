/*
Given an array of n integers, find for each array position the nearest position to its left having a smaller value.
Input
The first input line has an integer n: the size of the array.
The second line has n integers x1,x2,…,xn: the array values.
Output
Print n integers: for each array position the nearest position with a smaller value.
If there is no such position, print 0.
Constraints
1=n=2·10^5
1=xi=10^9
Example
Input:
8
2 5 1 4 8 3 2 5
Output:
0 1 0 3 4 3 3 7
SOLUTION
In a list of numbers A, the nearest smaller value (NSV) to an entry A_i is the last entry
preceding it with a smaller value, if any; that is, the entry A_j with greatest j < i such that A_j < A_i.
The all nearest smaller values (ANSV) problem is that of computing the NSV for each number in the list.
If k < j < i, then it is only possible for A_k to be a NSV for A_i if A_k < A_j,
otherwise A_j will always be both smaller and "nearer".
If A_j is smaller than A_i, then A_j is the NSV for A_i.
Hence the subarray between A_k and A_j can be safely discarded
because these values are greater than or equals A_j and hence cannot be NSV for A_i.
Time O(N)
Space O(N): stack to store smaller values
See https://wcipeg.com/wiki/All_nearest_smaller_values
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> solve(int n, vector<int> xs)
{
    vector<int> res(n);
    vector<tuple<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        // delete all preceding items that are not smaller than curr
        while (!st.empty() && get<0>(st.back()) >= xs[i])
        {
            st.pop_back();
        }
        if (st.empty())
        {
            res[i] = 0;
        }
        else
        {
            res[i] = get<1>(st.back());
        }
        st.push_back(make_tuple(xs[i], i + 1));
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> xs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> xs[i];
    }
    vector<int> res = solve(n, xs);
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
