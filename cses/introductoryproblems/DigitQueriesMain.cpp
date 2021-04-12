/*
Consider an infinite string that consists of all positive integers in increasing order:
12345678910111213141516171819202122232425...
Your task is to process q queries of the form: what is the digit at position k in the string?
Input
The first input line has an integer q: the number of queries.
After this, there are q lines that describe the queries.
Each line has an integer k: a 1-indexed position in the string.
Output
For each query, print the corresponding digit.
Constraints
1≤q≤1000
1≤k≤10^18
Example
Input:
3
7
19
12
Output:
7
4
1
SOLUTION
Building or iterating the whole string takes far too long. Instead group the numbers by length:
length 1 digit:  1 to 9 -> 9 numbers => 9 digits total
length 2 digits: 10 to 99 -> 90 numbers => 180 digits total
length 3 digits: 100 to 999 -> 900 numbers => 2700 digits total
length 4 digits: 1000 to 9999 -> 9000 numbers => 36000 digits total
Hence k = SUM(9 * head * len) + remainder
Head is the first number of the group e.g. 1, 10, 100, ...
Time O(1): each query takes constant time.
Space O(1)
References
- https://codereview.stackexchange.com/questions/256773/digit-queries-cses-solution-giving-tle
- https://codeforces.cc/blog/entry/86587?
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

char solve(ll k)
{
    ll len = 1, head = 1;
    // k is greater than the position of the last digit in the previous group 
    while (k > 9 * head * len) {
        k -= 9 * head * len;
        ++len;
        head *= 10;
    }
    // index of number in this group, index zero is the head
    // minus 1 because k is 1-indexed.
    ll q = (k - 1) / len;
    ll r = (k - 1) % len;
    return to_string(head + q)[r];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q, k;
    cin >> q;
    while (q--) {
        cin >> k;
        cout << solve(k) << "\n";
    }
    return 0;
}
