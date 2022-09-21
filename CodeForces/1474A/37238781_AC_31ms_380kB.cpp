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
		int n;
		cin >> n;
		string v;
		 cin >> v;
		int prev = 0;
		string s = "";
		map<pair<int, int>, char >mp = {{{1,2},'0'},{{1,1},'1'},{{1,0},'1'},{{0,2},'1'},{{0,1},'0'},{{0,0},'1'} };
		for (int i = 0; i < n; i++)
		{
			s += mp[{v[i]-'0', prev}];

			prev = v[i]-'0' + mp[{v[i] - '0', prev}]-'0';
		}
		cout << s << endl;
	}

	return 0;
}