/*
You are given an array that contains each number between 1…n exactly once. 
Your task is to collect the numbers from 1 to n in increasing order.
On each round, you go through the array from left to right and collect as many numbers as possible. 
What will be the total number of rounds?
Input
The first line has an integer n: the array size.
The next line has n integers x1,x2,…,xn: the numbers in the array.
Output
Print one integer: the number of rounds.
Constraints
1≤n≤2⋅10^5
Example
Input:
5
4 2 1 5 3
Output:
3
SOLUTION
Example can be broken down into the following steps:
2 <- 1
2 -> 3
4 <- 3
4 -> 5
Number of rounds starts at 1 and incremented by the #backward arrows.
Time O(N)
Space O(N): store indices of values 1..N

References:
- https://www.youtube.com/watch?v=lhhHCZYoJvs
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x;
    cin >> n;
    vector<ll> ind(n + 1);
    for (ll i = 0; i < n; i++)
    {
        cin >> x;
        ind[x] = i;
    }
    ll res = 1, j = ind[1];
    for (ll i = 2; i < n + 1; i++)
    {
        // Prev number found on the right (backward arrow)
        if (j > ind[i])
            res++;
        j = ind[i];
    }
    cout << res;
    return 0;
}