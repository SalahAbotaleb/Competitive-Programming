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
		int n,m;
		cin >> n >> m;
		vector<int>gif(n);
		vector<int>v(m);
		for (auto& it : gif) cin >> it;
		for (auto& it : v) cin >> it;
		sort(gif.begin(), gif.end());
		sort(v.begin(), v.end());
		int cgiff = n-1;
		int cstu = 0;
		int take = n - m;
		ll res = 0;
		while (cstu < m)
		{
			int mx = gif[cgiff];
			int mn;
			if (v[cstu] == 1)
				mn = mx;
			else mn = gif[take - v[cstu] +1], take -= (v[cstu]-1);
			res += mx + mn;
			cstu++;
			cgiff--;
		}
		cout << res << endl;
	}
	
	return 0;
}