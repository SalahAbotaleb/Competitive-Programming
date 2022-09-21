#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#define ll long long
using namespace std;
const int N = 1e6+5;
int arr[N];
void primes()
{
	arr[0] = arr[1] = 1;
	for (int i = 2; i * i < N; i++)
	{
		if (arr[i] == 0)
		{
			for (int j = i+i; j < N; j += i)
			{
				arr[j] = 1;
			}
		}
	}
}
ll power(ll b, ll pow)
{
	ll ans = 1;
	while (pow != 0)
	{
		if (pow & 1)
			ans *= b;
		b *= b;
		pow >>= 1;
	}
	return ans;
}

void init() {
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int main()
{
	init();
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m;
		cin >> n >> m;
		bool ok = 0;
		map<pair<int, int>, pair<int, int>>mp;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			x = x % m;
			int comp = m - x;
			if (x == 0)
			{
				ok = 1;
				continue;
			}
			if (mp.find({ x,comp }) != mp.end())
				mp[{x, comp}].first++;
			else
				if (mp.find({ comp,x }) != mp.end())
					mp[{comp, x}].second++;
				else
					mp[{x, comp}].first++;
		}
		int res = 0;
		for (auto it : mp)
		{
			if (it.first.first == it.first.second)
			{
				res++;
				continue;
			}
			int mn = min(it.second.first, it.second.second);
			int mx = max(it.second.first, it.second.second);
			if (mx - mn == 0)
				res++;
			else
				res += mx - mn;
		}
		cout << res+ok << endl;
	}
	
	return 0;
}