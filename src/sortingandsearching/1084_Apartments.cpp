/*
There are n applicants and m free apartments.
Your task is to distribute the apartments so that as many applicants as possible will get an apartment.
Each applicant has a desired apartment size,
and they will accept any apartment whose size is close enough to the desired size.
Input
The first input line has three integers n, m, and k:
the number of applicants, the number of apartments, and the maximum allowed difference.
The next line contains n integers a1,a2,…,an:
the desired apartment size of each applicant.
If the desired size of an applicant is x, he or she will accept any apartment whose size is between x−k and x+k.
The last line contains m integers b1,b2,…,bm: the size of each apartment.
Output
Print one integer: the number of applicants who will get an apartment.
Constraints
1 <= n,m <= 2⋅10^5
0 <= k <= 10^9
1 <= ai,bi <= 10^9
Example
Input:
4 3 5
60 45 80 60
30 60 75
Output:
2
SOLUTION
Time O(N lg N + M lg M)
Space O(1)
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<ll> applicants, vector<ll> apartments, ll k)
{
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());
    ll res = 0, i = 0, j = 0;
    ll n = (ll)applicants.size();
    ll m = (ll)apartments.size();
    while (i < n && j < m)
    {
        if (abs(applicants[i] - apartments[j]) <= k)
        {
            res++;
            i++;
            j++;
            continue;
        }
        // Applicant's request is larger than current apartment, move to next apartment.
        if (applicants[i] > apartments[j])
        {
            j++;
            continue;
        }
        // this apartment and the rest are larger than applicant's requirement
        // so move on to the next applicant
        i++;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> applicants(n);
    vector<ll> apartments(m);
    for (ll i = 0; i < n; i++)
        cin >> applicants[i];
    for (ll i = 0; i < m; i++)
        cin >> apartments[i];
    cout << solve(applicants, apartments, k);
    return 0;
}