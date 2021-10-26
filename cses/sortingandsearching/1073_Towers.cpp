/*
You are given n cubes in a certain order, and your task is to build towers using them.
Whenever two cubes are one on top of the other, the upper cube must be smaller than the lower cube.
You must process the cubes in the given order.
You can always either place the cube on top of an existing tower, or begin a new tower.
What is the minimum possible number of towers?
Input
The first input line contains an integer n: the number of cubes.
The next line contains n integers k1,k2,…,kn: the sizes of the cubes.
Output
Print one integer: the minimum number of towers.
Constraints
1≤n≤2⋅10^5
1≤ki≤10^9
Example
Input:
5
3 8 2 1 5
Output:
2
SOLUTION
Put the towers in a sorted array; each element represents the top cube of a tower.
Start with the first tower and grow this array iteratively (maintain the sorted property).
Time O(N lg N): binary search where to insert in sorted array
Space O(N): store the towers in an array
*/
#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> ks)
{
    multiset<int> towers;
    for (int i = 0; i < n; i++)
    {
        // find the first "bigger" tower top to place this cube
        auto it = towers.upper_bound(ks[i]);
        if (it != towers.end())
            towers.erase(it);
        // put new cube on top
        towers.insert(ks[i]);
    }
    return (int)towers.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> ks(n);
    for (int i = 0; i < n; i++)
        cin >> ks[i];
    cout << solve(n, ks);
    return 0;
}
