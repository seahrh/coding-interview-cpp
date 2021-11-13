/*
You are given an array that contains each number between 1…n exactly once. 
Your task is to collect the numbers from 1 to n in increasing order.
On each round, you go through the array from left to right and collect as many numbers as possible.
Given m operations that swap two numbers in the array, 
your task is to report the number of rounds after each operation.
Input
The first line has two integers n and m: the array size and the number of operations.
The next line has n integers x1,x2,…,xn: the numbers in the array.
Finally, there are m lines that describe the operations. 
Each line has two integers a and b: the numbers at positions a and b are swapped.
Output
Print m integers: the number of rounds after each swap.
Constraints
1≤n,m≤2⋅10^5
1≤a,b≤n
Example
Input:
5 3
4 2 1 5 3
2 3
1 5
2 3
Output:
2
3
4
SOLUTION
Number of rounds starts at 1 
and incremented by the #inversions of consecutive numbers (backward arrows).
Time O(N)
Space O(N): store indices of values 1..N
Each query takes O(1) time.

References
- https://www.youtube.com/watch?v=LEL3HW4dQew
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, x, y, a, b;
    cin >> n >> m;
    vector<ll> xs(n + 1);
    vector<ll> ind(n + 2);
    for (ll i = 1; i < n + 1; i++)
    {
        cin >> xs[i];
        ind[xs[i]] = i;
    }
    ll res = 1;
    x = ind[1];
    for (ll i = 2; i < n + 1; i++)
    {
        // Inversion: prev number found on the right
        if (x > ind[i])
            res++;
        x = ind[i];
    }
    while (m--)
    {
        cin >> a >> b;
        x = xs[a], y = xs[b];
        swap(xs[a], xs[b]);
        // 2nd comparison is >= or <=
        // bec it can be adjacent swap e.g. swap(xs[1], xs[2])
        if (ind[x - 1] < ind[x] && ind[x - 1] >= b)
            res++;
        if (ind[x - 1] > ind[x] && ind[x - 1] <= b)
            res--;
        if (ind[x] < ind[x + 1] && b >= ind[x + 1])
            res++;
        if (ind[x] > ind[x + 1] && b <= ind[x + 1])
            res--;
        ind[x] = b;
        if (ind[y - 1] < ind[y] && ind[y - 1] >= a)
            res++;
        if (ind[y - 1] > ind[y] && ind[y - 1] <= a)
            res--;
        if (ind[y] < ind[y + 1] && a >= ind[y + 1])
            res++;
        if (ind[y] > ind[y + 1] && a <= ind[y + 1])
            res--;
        ind[y] = a;
        cout << res << endl;
    }
    return 0;
}