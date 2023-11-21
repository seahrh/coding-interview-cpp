/*
There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.
Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed x.
You know the weight of every child.
What is the minimum number of gondolas needed for the children?
Input
The first input line contains two integers n and x: the number of children and the maximum allowed weight.
The next line contains n integers p1,p2,…,pn: the weight of each child.
Output
Print one integer: the minimum number of gondolas.
Constraints
1≤n≤2⋅10^5
1≤x≤10^9
1≤pi≤x
Example
Input:
4 10
7 2 3 9
Output:
3
See https://cses.fi/problemset/task/1090
SOLUTION
Sort the children by weight. Start with the heaviest child and try to pair with the lightest child.
If the lightest child cannot be added to the gondola, then the heavy child must take the gondola alone,
because there isn't a lighter child.
Time O(N lg N)
Space O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int n, int x, vector<int> ps)
{
    sort(ps.begin(), ps.end());
    int res = 0;
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        if (ps[i] + ps[j] <= x)
            i++;
        j--;
        res++;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> ps(n);
    for (int i = 0; i < n; i++)
        cin >> ps[i];
    cout << solve(n, x, ps) << endl;
    return 0;
}
