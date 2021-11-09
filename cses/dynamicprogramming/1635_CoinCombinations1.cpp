/*
Consider a money system consisting of n coins. Each coin has a positive integer value.
Calculate the number of distinct ways you can produce a money sum x using the available coins.
For example, if the coins are {2,3,5} and the desired sum is 9, there are 8 ways:
2+2+5
2+5+2
5+2+2
3+3+3
2+2+2+3
2+2+3+2
2+3+2+2
3+2+2+2
Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c1,c2,…,cn: the value of each coin.
Output
Print one integer: the number of ways modulo 10^9+7.
Constraints
1≤n≤100
1≤x≤10^6
1≤ci≤10^6
Example
Input:
3 9
2 3 5
Output:
8
SOLUTION
dp[i] = number of ways to make sum i 
Loop over the possibilities for last coin added (all coins <= current target).
There are dp[x-v] ways to make x, when adding a coin with value v **last**.
Time O(N lg N + X lg N)
Space O(X): memo array
*/
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int solve(int n, int x, vector<int> cs)
{
    sort(cs.begin(), cs.end());
    vector<int> dp(x + 1);
    // Base case: all the coins that equals target
    for (int i = 0; i < n; i++)
    {
        if (cs[i] > x)
            break;
        dp[cs[i]] = 1;
    }
    // start loop after 1st coin
    for (int i = cs[0] + 1; i < x + 1; i++)
    {
        // get all coins <= current target
        auto it = upper_bound(cs.begin(), cs.end(), i);
        int hi = distance(cs.begin(), it);
        for (int j = 0; j < hi; j++)
            (dp[i] += dp[i - cs[j]]) %= mod;
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
        cin >> cs[i];
    cout << solve(n, x, cs);
    return 0;
}