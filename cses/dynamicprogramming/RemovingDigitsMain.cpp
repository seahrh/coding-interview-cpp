/*
You are given an integer n. On each step, you may subtract from it any one-digit number that appears in it.
How many steps are required to make the number equal to 0?
Input
The only input line has an integer n.
Output
Print one integer: the minimum number of steps.
Constraints
1≤n≤10^6
Example
Input:
27
Output:
5
Explanation: An optimal solution is 27→20→18→10→9→0.
SOLUTION
dp[x] = minimum number of operations to go from x to zero.
When considering a number x, for each digit in the decimal representation of x, we can try to remove it.
Recurring relation: dp[x] = min of dp[x-d] for each digit d of x
Time O(N)
Space O(N)
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    vector<int> dp(n + 1, n);
    dp[0] = 0;
    int remainder, digit;
    for (int i = 1; i <= n; i++) {
        remainder = i;
        // Time O(1) because max 7 digits
        while (remainder != 0) {
            digit = remainder % 10;
            if (remainder - digit >= 0) {
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
            // remove the last digit
            remainder /= 10;
        }
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}

