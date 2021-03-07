/*
In a movie festival n movies will be shown. You know the starting and ending time of each movie.
What is the maximum number of movies you can watch entirely?
Input
The first input line has an integer n: the number of movies.
After this, there are n lines that describe the movies.
Each line has two integers a and b: the starting and ending times of a movie.
Output
Print one integer: the maximum number of movies.
Constraints
1≤n≤2⋅10^5
1≤a<b≤10^9
Example
Input:
3
3 5
4 9
5 8
Output:
2
SOLUTION
Sort movies by end time. If the start time of the next movie falls after the last movie has ended, add it.
Time O(N lg N)
Space O(1)
*/
#include <bits/stdc++.h>
using namespace std;

bool second_ordering(const tuple<int, int> &left, const tuple<int, int> &right)
{
    return (get<1>(left) < get<1>(right));
}

int solve(int n, vector<tuple<int, int>> movies)
{
    int res = 0;
    sort(movies.begin(), movies.end(), second_ordering);
    int a, b;
    b = 0;
    for (int i = 0; i < n; i++)
    {
        a = get<0>(movies[i]);
        if (a >= b)
        {
            res++;
            b = get<1>(movies[i]);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b;
    cin >> n;
    vector<tuple<int, int>> movies(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        movies[i] = make_tuple(a, b);
    }
    cout << solve(n, movies);
    return 0;
}
