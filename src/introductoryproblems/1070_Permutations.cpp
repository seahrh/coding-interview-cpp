/*
A permutation of integers 1,2,…,n is called beautiful if there are no adjacent elements whose difference is 1.
Given n, construct a beautiful permutation if such a permutation exists.
Input
The only input line contains an integer n.
Output
Print a beautiful permutation of integers 1,2,…,n.
If there are several solutions, you may print any of them. If there are no solutions, print "NO SOLUTION".
Constraints
1≤n≤10^6
Example 1
Input:
5
Output:
4 2 5 3 1
Example 2
Input:
3
Output:
NO SOLUTION
SOLUTION
Pick all the even numbers first then the odd numbers, in ascending order.
This ensures no adjacent elements with difference of 1.
Time O(N): two passes
Space O(N): store the output, else O(1) if the output is printed.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n)
{
    vector<int> res;
    if (n == 1)
    {
        res.push_back(1);
        return res;
    }
    if (n < 4)
    {
        return res;
    }
    for (int i = 2; i <= n; i += 2)
    {
        res.push_back(i);
    }
    for (int i = 1; i <= n; i += 2)
    {
        res.push_back(i);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> res = solve(n);
    if (res.empty())
    {
        cout << "NO SOLUTION";
    }
    else
    {
        for (int i : res)
        {
            cout << i << " ";
        }
    }
    return 0;
}
