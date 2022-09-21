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

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n,val;
		cin >> n >> val;
		int ok = 0;
		map<int, int>mp;
		vector<int>v;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			mp[x]++;
			v.push_back(x);
			if (x > val)
				ok = 1;
		}
		if (ok == 0)
		{
			cout << "YES" << endl;
			continue;
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < n; i++)
		{
			if (v[i] < val)
			{
				auto it = upper_bound(v.begin(), v.end(), val-v[i]);
				if (it == v.begin())
					continue;
				it--;
				if (*it != v[i])
				{
					ok = 0;
					break;
				}
				else
				{
					if (mp[*it] > 1)
					{
						ok = 0;
						break;
					}
				}
			}
		}
		cout << (!ok ? "YES\n" : "NO\n");
	}

	return 0;
}