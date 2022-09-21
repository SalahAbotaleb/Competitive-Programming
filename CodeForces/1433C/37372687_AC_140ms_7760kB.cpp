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
const int N = 1e5;
int arr[N];
void primes(vector<int>& v)
{
	arr[0] = arr[1] = 1;
	for (int i = 2; i * i < N; i++)
	{
		if (arr[i] == 0)
		{
			v.push_back(i);
			for (int j = i; j < N; j += i)
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
		vector<int>v(n);
		for (auto& it : v) cin >> it;
		vector<pair<int, int>> p;
		for (int i = 0; i < n; i++)
		{
			p.push_back({ v[i],i });
		}
		sort(p.begin(), p.end(), [](pair<int, int>a, pair<int, int>b)
			{
				if (a.first == b.first)
					return a.second < b.second;
				return a.first > b.first;
			});
		bool ok = 0;
		for (int i = 0; i < n; i++)
		{
			int yes = 0;
			int idx = p[i].second;
			if (idx + 1 < n)
				if (v[idx] > v[idx + 1])
					yes ++;
			if (idx - 1 > -1)
				if (v[idx] > v[idx - 1])
					yes ++;
			if (yes && v[idx] + yes + abs(idx - p[0].second) > p[0].first)
			{
				ok = 1;
				cout << idx + 1 << endl;
				break;
			}
		}
		if (!ok)
			cout << -1 << endl;
	}
}