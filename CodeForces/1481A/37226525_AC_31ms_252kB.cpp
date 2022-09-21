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
		int a, b;
		cin >> a >> b;
		map<char, int> mp;
		map<char, int> mp2;
		if (a > 0)
			mp['R']=a;
		if (a < 0)
			mp['L']=abs(a);
		if (b > 0)
			mp['U']=b;
		if (b < 0)
			mp['D'] = abs(b);
		string s;
		cin >> s;
		for (auto x : s) mp2[x]++;
		bool ok = 1;
		for(auto it=mp.begin();it!=mp.end();it++)
			if (mp2.find(it->first) == mp2.end() || it->second > mp2[it->first])
			{
				ok = 0;
				break;
			}
		cout << (ok ? "YES\n" : "NO\n");
	}

	return 0;
}