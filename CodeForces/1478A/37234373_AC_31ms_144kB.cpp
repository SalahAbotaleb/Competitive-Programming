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
int bs(ll val,ll b)
{

	int l = 0, r = 50;
	r = 1;
	while (power(b, r) <= val)
	{
		r++;
	}
	return r;
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		map<int, int>mp;
		int mx = INT_MIN;
		for (int i = 0; i < n; i++)
		{
			int x; cin >> x;
			mp[x]++;
			mx = max(mx, mp[x]);
		}
		cout << mx << endl;
	}

	return 0;
}