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
dp[i] = min #coins to make sum i
We look at the last coin added to get sum x, say it has value v.
We need dp[x-v] coins to get value x-v, and 1 coin for value v.
Therefore we need dp[x-v]+1 coins if we are to use a coin with value v.
Time O(N lg N + XN)
Space O(X): memo array
References
- https://codeforces.com/blog/entry/70018
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> cs(n);
    for (int i = 0; i < n; i++)
        cin >> cs[i];
    // optimization for checking all coins <= current target
    sort(cs.begin(), cs.end());
    int impossible = x + 1;
    vector<int> dp(x + 1, impossible);
    // Base case: last coin reduces sum to zero
    dp[0] = 0;
    for (int i = cs[0]; i < x + 1; i++)
        // consider all coins <= current target
        // also checks (i - cs[j] >= 0) to prevent IndexOutOfBounds!
        for (int j = 0; j < n; j++)
        {
            if (cs[j] > i)
                break;
            dp[i] = min(dp[i], dp[i - cs[j]] + 1);
        }
    if (dp[x] == impossible)
        cout << -1;
    else
        cout << dp[x];
    return 0;
}