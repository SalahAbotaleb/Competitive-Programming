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
		ll a, b;
		cin >> a >> b;
		if (b > a)
		{		cout << 1 << endl;
		continue;
		}
		int cnt = 0;
		if (b == 1)
			cnt++, b++;
		int ib = b;
		int pre = INT_MAX;
		while ((bs(a, b) + b - ib) <= pre)
		{
			pre = bs(a, b) + b-ib;
			b++;
		}
		cout << pre+cnt << endl;
	}

	return 0;
}