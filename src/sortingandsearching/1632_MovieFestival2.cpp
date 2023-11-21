/*
In a movie festival, n movies will be shown. 
Syrjälä's movie club consists of k members, who will be all attending the festival.
You know the starting and ending time of each movie. 
What is the maximum total number of movies the club members can watch entirely if they act optimally?
Input
The first input line has two integers n and k: the number of movies and club members.
After this, there are n lines that describe the movies. 
Each line has two integers a and b: the starting and ending time of a movie.
Output
Print one integer: the maximum total number of movies.
Constraints
1≤k≤n≤2⋅10^5
1≤a<b≤10^9
Example
Input:
5 2
1 5
8 10
3 6
2 5
6 9
Output:
4
SOLUTION
Greedy method. We process films in order of end time. 
For every film, if no person is free at start time, we dont watch that film. 
If at least one person free, we use the one latest free.
Maintain BST of person's available times. Initially all persons are available at time 0.

Time O(N lg N + K lg K + N lg K)
Space O(N + K)

References
- https://usaco.guide/problems/cses-1632-movie-festival-ii/solution
- https://codeforces.com/blog/entry/82695
*/
#include <bits/stdc++.h>
// Sort by end time, hence tuple (end, start)
#define pai tuple<int, int>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, a, b;
    cin >> n >> k;
    vector<pai> ms(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        ms[i] = {b, a};
    }
    sort(ms.begin(), ms.end());
    int res = 0;
    multiset<int> ava;
    while (k--)
        ava.insert(0);
    for (auto [b, a] : ms)
    {
        // first person avail after start time
        // any person to the left is avail <= start time
        auto it = ava.upper_bound(a);
        if (it == ava.begin())
            continue;
        ava.erase(--it);
        ava.insert(b);
        res++;
    }
    cout << res;
    return 0;
}