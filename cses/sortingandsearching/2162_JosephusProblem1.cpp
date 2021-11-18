/*
Consider a game where there are n children (numbered 1,2,…,n) in a circle. 
During the game, every second child is removed from the circle, until there are no children left. 
In which order will the children be removed?
Input
The only input line has an integer n.
Output
Print n integers: the removal order.
Constraints
1=n=2·10^5
Example
Input:
7
Output:
2 4 6 1 5 3 7
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // a is in powers of 2 beginning from 1
    // b is offset
    int n, a = 1, b = 0;
    cin >> n;
    while (n > 0)
    {
        for (int i = 2; i < n + 1; i += 2)
            cout << a * i + b << ' ';
        // odd number, start next sequence with 1
        if (n & 1)
        {
            cout << a + b << ' ';
            b += a;
        }
        else
            b -= a;
        // left bit shift, multiply by 2
        a <<= 1;
        // right bit shift, divide by 2
        // every iteration removes half of remainder
        n >>= 1;
    }
    return 0;
}