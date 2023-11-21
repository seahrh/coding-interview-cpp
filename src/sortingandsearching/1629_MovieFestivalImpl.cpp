#include "src/sortingandsearching/package.hpp"

bool second_ordering(const tuple<int, int> &left, const tuple<int, int> &right)
{
    return (get<1>(left) < get<1>(right));
}

int movie_festival(int n, vector<tuple<int, int>> movies)
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
