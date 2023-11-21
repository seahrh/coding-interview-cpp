/*
You are in a book shop which sells n different books. You know the price and number of pages of each book.
You have decided that the total price of your purchases will be at most x.
What is the maximum number of pages you can buy? You can buy each book at most once.
Input
The first input line contains two integers n and x: the number of books and the maximum total price.
The next line contains n integers h1,h2,…,hn: the price of each book.
The last line contains n integers s1,s2,…,sn: the number of pages of each book.
Output
Print one integer: the maximum number of pages.
Constraints
1≤n≤1000
1≤x≤10^5
1≤hi,si≤1000
Example
Input:
4 10
4 8 5 3
5 12 8 1
Output:
13
Explanation: You can buy books 1 and 3. Their price is 4+5=9 and the number of pages is 5+8=13.
SOLUTION
0/1 Knapsack problem
Bottom-up DP (tabulation) works only if weights and capacity are positive integers.
dp[i][j] = max #pages using only first i books and budget j.
Recurrence: dp[i][j] = max(not take ith item, take ith item)
Base case: dp[i][0] = 0, dp[0][j] = 0
Time O(NB)
Space O(NB)

See https://www.youtube.com/watch?v=nLmhmB6NzcM
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int n, int x, vector<int> prices, vector<int> pages)
{
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < x + 1; j++)
        {
            int take = 0;
            // i is 1-indexed so (i-1) is the ith book!
            int k = j - prices[i - 1];
            if (k >= 0)
                take = dp[i - 1][k] + pages[i - 1];
            dp[i][j] = max(dp[i - 1][j], take);
        }
    return dp[n][x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> prices(n);
    vector<int> pages(n);
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];
    cout << solve(n, x, prices, pages) << endl;
    return 0;
}
