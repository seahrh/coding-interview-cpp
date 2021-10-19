/*
Consider a money system consisting of n coins. Each coin has a positive integer value.
Produce a sum of money x using the available coins in such a way that the number of coins is minimal.
For example, if the coins are {1,5,7} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c1,c2,…,cn: the value of each coin.
Output
Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print −1.
Constraints
1≤n≤100
1≤x≤10^6
1≤ci≤10^6
Example
Input:
3 11
1 5 7
Output:
3
SOLUTION
We look at the last coin added to get sum x, say it has value v.
We need dp[x-v] coins to get value x-v, and 1 coin for value v.
Therefore we need dp[x-v]+1 coins if we are to use a coin with value v.
Time O(X lg N): binary search coins in the loop
Space O(X): memo array
See https://codeforces.com/blog/entry/70018
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int n, int x, vector<int> cs)
{
    sort(cs.begin(), cs.end());
    int impossible = x + 1;
    vector<int> dp(x + 1, impossible);
    // single coin counts
    for (int c : cs)
    {
        if (c > x)
        {
            break;
        }
        dp[c] = 1;
    }
    // start looping target after 1st coin
    for (int i = cs[0] + 1; i <= x; i++)
    {
        if (dp[i] != impossible)
            continue;
        int best = impossible;
        // consider all coins <= current target
        // prevent IndexOutOfBounds when looking up dp array to the left!
        auto it = upper_bound(cs.begin(), cs.end(), i);
        int hi = distance(cs.begin(), it);
        for (int j = 0; j < hi; j++)
        {
            best = min(best, dp[i - cs[j]] + 1);
        }
        dp[i] = best;
    }
    if (dp[x] == impossible)
    {
        return -1;
    }
    return dp[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> cs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cs[i];
    }
    cout << solve(n, x, cs);
    return 0;
}