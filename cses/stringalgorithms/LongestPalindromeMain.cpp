/*
Given a string, your task is to determine the longest palindromic substring of the string.
For example, the longest palindrome in aybabtu is bab.
Input
The only input line contains a string of length n. Each character is one of a–z.
Output
Print the longest palindrome in the string. If there are several solutions, you may print any of them.
Constraints
1≤n≤10^6
Example
Input:
aybabtu
Output:
bab
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

string solve(string s)
{
    ll n = (ll)s.size();
    vector<vector<ll>> dp(n, vector<ll>(2));
    // head and tail of longest palindrome
    ll x1 = 0, y1 = -1;
    ll x2 = 0, y2 = -1;
    ll mx = 0, ans = 0;
    for (ll i = 0; i < n; i++)
    {
        // odd length palindrome where ith item is centre
        // k is length of partition
        ll k = 1;
        // explored region
        // k is either half of longest palindrome found so far
        // or 
        if (i <= y1)
            k = min(dp[x1 + y1 - i][0], y1 - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
            k++;
        // get last successful k
        dp[i][0] = k--;
        // update head and tail of longest palindrome
        if (i + k > y1)
            x1 = i - k, y1 = i + k;
        // if this is odd length palindrome, why -1?
        if (2 * dp[i][0] - 1 > mx)
            ans = i - k, mx = 2 * dp[i][0] - 1;
        // even length palindrome where ith item is head of right partition
        k = 0;
        if (i <= y2)
            k = min(dp[x2 + y2 - i + 1][1], y2 - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k])
            k++;
        dp[i][1] = k--;
        if (i + k > y2)
            x2 = i - k - 1, y2 = i + k;
        if (2 * dp[i][1] > mx)
            ans = i - k - 1, mx = 2 * dp[i][1];
    }
    return s.substr(ans, mx);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    cout << solve(s);
    return 0;
}