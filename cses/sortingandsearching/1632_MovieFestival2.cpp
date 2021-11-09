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
*/
#include <bits/stdc++.h>
// tuple (time, is_start)
// process end=0 before start=1, so resource can be freed up
#define tri tuple<int, bool, int>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, a, b;
    cin >> n >> k;
    vector<tri> tim;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        tim.push_back({a, 1, i});
        tim.push_back({b, 0, i});
    }
    sort(tim.begin(), tim.end());
    int res = 0;
    // a is #club members unassigned
    set<int> wat;
    for (auto [t, start, i] : tim)
    {
        if (start)
        {
            if ((int)wat.size()<k)
            {
                wat.insert(i);
                res++;
            }
            continue;
        }
        // movie ended, return resource
        wat.erase(i);
    }
    cout << res;
    return 0;
}