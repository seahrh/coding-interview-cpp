/*
Your task is to count for k=1,2,…,n the number of ways two knights can be placed on a k×k chessboard so that they do not attack each other.
Input
The only input line contains an integer n.
Output
Print n integers: the results.
Constraints
1≤n≤10000
Example
Input:
8
Output:
0
6
28
96
252
550
1056
1848
SOLUTION
Total number of ways two pieces can be placed on board is given by:
n^2 choose 2 = (n^2)! / 2! (n^2 - 2)! = n^2(n^2 - 1) / 2
Number of ways in which two knights can attack each other is equal to twice the number of 2x3 and 3x2 matrices that can fit in NxN matrix.
Because in every 2x3 or 3x2 matrix we can have 2 distinct position such that both can attack each other.
Now the number of 3x2 matrix in nxn = (n-2)(n-1) . Similarly number of 2x3 matrix also equals to (n-2)(n-1).
As there are 2 distinct positions in each such matrix our ans becomes 4(n-1)(n-2).
Time O(N): each iteration of N takes O(1) time.
Space O(1) 
See
- https://discuss.codechef.com/t/cses-two-knights-problem-help-needed/69448/12
- https://math.stackexchange.com/questions/3949553/cses-problem-set-two-knights-question-https-cses-fi-problemset-task-1072
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll n)
{
    return n * n * (n * n - 1) / 2 - (4 * (n - 1) * (n - 2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cout << solve(i) << "\n";
    }
    return 0;
}