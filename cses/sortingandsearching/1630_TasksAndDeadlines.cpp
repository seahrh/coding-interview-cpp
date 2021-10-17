/*
You have to process n tasks. Each task has a duration and a deadline,
and you will process the tasks in some order one after another.
Your reward for a task is d−f where d is its deadline and f is your finishing time.
(The starting time is 0, and you have to process all tasks even if a task would yield negative reward.)
What is your maximum reward if you act optimally?
Input
The first input line has an integer n: the number of tasks.
After this, there are n lines that describe the tasks.
Each line has two integers a and d: the duration and deadline of the task.
Output
Print one integer: the maximum reward.
Constraints
1≤n≤2⋅10^5
1≤a,d≤10^6
Example
Input:
3
6 10
8 15
5 12
Output:
2
SOLUTION
To minimise penalty, sort the tasks by shortest duration first, then shortest deadline.
Time O(N lg N)
Space O(1)
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(int n, vector<tuple<ll, ll>> tasks)
{
    ll res = 0, curr = 0;
    sort(tasks.begin(), tasks.end());
    for (int i = 0; i < n; i++)
    {
        curr += get<0>(tasks[i]);
        res += get<1>(tasks[i]) - curr;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<tuple<ll, ll>> tasks(n);
    ll a, d;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> d;
        tasks[i] = make_tuple(a, d);
    }
    cout << solve(n, tasks);
    return 0;
}
