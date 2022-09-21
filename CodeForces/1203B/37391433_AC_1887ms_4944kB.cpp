#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#include <iomanip>
#include <stack>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const ll loo = 0x3f3f3f3f3f3f3f3f;
int arr[N];
void primes()
{
	arr[0] = arr[1] = 1;
	for (int i = 2; i * i < N; i++)
	{
		if (arr[i] == 0)
		{
			for (int j = i + i; j < N; j += i)
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
		int n;
		cin >> n;
		int arr[10000 + 5] = { };
		for (int i = 0; i < 4 * n; i++)
		{
			int x; cin >> x; arr[x]++;
		}
		vector<pair<int,int>>v;
		for (int i = 0; i < 10005; i++)
		{
			if (arr[i]/2)
			{
				v.push_back({ i,arr[i]/2 });
			}
		}
		map<int, int>mp;
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = i + 1; j < v.size(); j++)
				for (int k = 0; k < min(v[i].second, v[j].second); k++)
				{
					mp[v[i].first * v[j].first]++;
				}
		}
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].second / 2)
			{
				for (int j = 0; j < v[i].second / 2; j++)
					mp[v[i].first * v[i].first]++;
			}
		}
		bool ok = 0;
		for (auto it : mp)
		{
			if (it.second >= n)
			{
				ok = 1;
				break;
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
	return 0;
}