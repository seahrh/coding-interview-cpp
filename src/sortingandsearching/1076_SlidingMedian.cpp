/*
You are given an array of n integers.
Your task is to calculate the median of each window of k elements, from left to right.
The median is the middle element when the elements are sorted.
If the number of elements is even, there are two possible medians and we assume that the median is the smaller of them.
Input
The first input line contains two integers n and k: the number of elements and the size of the window.
Then there are n integers x1,x2,…,xn: the contents of the array.
Output
Print n−k+1 values: the medians.
Constraints
1≤k≤n≤2⋅10^5
1≤xi≤109
Example
Input:
8 3
2 4 3 5 8 1 2 1
Output:
3 4 5 5 2 1
SOLUTION
Time O(N lg K)
Space O(K)
Middle of two heaps
Invariants
- Lower heap cannot be empty
- Max size of upper heap is size of lower heap
- Max size of lower heap is (size of upper heap + 1)
Regardless of even or odd window length, median is always the largest item in lower heap.
In C++, use `multiset` (BSTs) for upper and lower heaps.
Use BST instead of priority_queue bec we need to binary search item to remove!
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void add(ll val, multiset<ll> &up, multiset<ll> &lo)
{
	if (lo.empty())
	{
		lo.insert(val);
		return;
	}
	ll median = *lo.rbegin();
	if (val > median)
	{
		up.insert(val);
		// move smallest item from upper to lower
		if ((ll)up.size() > (ll)lo.size())
		{
			lo.insert(*up.begin());
			up.erase(up.begin());
		}
	}
	else
	{
		lo.insert(val);
		// move largest item from lower to upper
		if ((ll)lo.size() > (ll)up.size() + 1)
		{
			up.insert(*lo.rbegin());
			// erase(lo.rbegin()) does not compile!
			// see https://stackoverflow.com/questions/8992658/multiset-erase-last-element
			lo.erase(--lo.end());
		}
	}
}

void remove(ll val, multiset<ll> &up, multiset<ll> &lo)
{
	// find gets the first equivalent item
	auto it = up.find(val);
	if (it != up.end())
	{
		up.erase(it);
		return;
	}
	it = lo.find(val);
	lo.erase(it);
	if (lo.empty())
	{
		lo.insert(*up.begin());
		up.erase(up.begin());
	}
}

vector<ll> sliding_median(ll n, ll k, vector<ll> xs)
{
	vector<ll> res;
	multiset<ll> up;
	multiset<ll> lo;
	for (ll i = 0; i < n; i++)
	{
		if (k == 1)
        {
            res.push_back(xs[i]);
            continue;
        }
		add(xs[i], up, lo);
		if ((ll)up.size() + (ll)lo.size() == k)
		{
			res.push_back(*lo.rbegin());
			remove(xs[i - k + 1], up, lo);
		}
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k;
	cin >> n >> k;
	vector<ll> xs(n);
	for (ll i = 0; i < n; i++)
		cin >> xs[i];
	vector<ll> res = sliding_median(n, k, xs);
	for (auto r = begin(res); r != end(res); ++r)
		cout << *r << " ";
	return 0;
}
