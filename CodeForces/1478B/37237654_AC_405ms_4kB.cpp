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
		int n,l;
		cin >> n >> l;
		while (n--)
		{
			int x;
			cin >> x;
			while (x > 0 && x % 10 != l && x<10*l)
			{
				x -= l;
			}
			cout << (x >= 0 ? "YES\n" : "NO\n");
		}
	}

	return 0;
}