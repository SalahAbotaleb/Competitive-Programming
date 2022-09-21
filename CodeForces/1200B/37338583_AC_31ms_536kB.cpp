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
		int n, m, k;
		cin >> n >> m >> k;
		bool ok = 1;
		vector<int>v(n);
		for (auto& it : v)cin >> it;
		for (int i = 0; i < n - 1; i++)
		{
			int old = v[i];
			int h1 = -k + v[i + 1];
			if (h1 > old)
			{
				if (m >= h1 - old)
				{
					m -= (h1 - old);
				}
				else
				{
					ok = 0;
					break;
				}
			}
			else
			{
				h1 = max(0, h1);
				m += (old - h1);
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
	return 0;
}