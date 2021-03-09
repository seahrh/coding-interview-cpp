/*
There are n books, and Kotivalo and Justiina are going to read them all.
For each book, you know the time it takes to read it.
They both read each book from beginning to end, and they cannot read a book at the same time.
What is the minimum total time required?
Input
The first input line has an integer n: the number of books.
The second line has n integers t1,t2,…,tn: the time required to read each book.
Output
Print one integer: the minimum total time.
Constraints
1≤n≤2⋅10^5
1≤ti≤10^9
Example
Input:
3
2 8 3
Output:
16
SOLUTION
Sort books by reading time. This ensures they cannot read a book at the same time.
So get a cumulative sum of reading times from both ends of the sorted books.
Terminate when sum(left) >= sum(right).
The result is the sum of the two partitions. There is no idle time even if one partition is longer than the other.
Because the other reader can start reading the other partition as soon as she is done with the first partition.
However this is not true if a partition contains only a single book as one book cannot be subdivided.
So the first reader who finishes her partition is forced to wait for the second reader to finish.
Time O(N lg N)
Space O(N): store cumulative sum of reading times from the right end
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(int n, vector<ll> ts)
{
    sort(ts.begin(), ts.end());
    vector<ll> right(n);
    ll _sum = 0; 
    for (int i = n - 1; i >= 0; i--)
    {
        _sum += ts[i];
        right[i] = _sum;
    }
    _sum = 0;
    // invariant: left partition can be empty but right partition must have at least 1 book!
    // If there is only 1 book, will not enter the loop
    for (int i = 0; i < n - 1; i++)
    {
        // left takes curr book
        _sum += ts[i];
        // right takes next book
        if (_sum >= right[i + 1])
        {
            return _sum + right[i + 1];
        }
    }
    return ts[n - 1] * 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> ts(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ts[i];
    }
    cout << solve(n, ts);
    return 0;
}
