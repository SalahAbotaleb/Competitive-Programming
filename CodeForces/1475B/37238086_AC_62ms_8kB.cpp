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
		int x;
		cin >> x;
		if (x < 2020)
		{
			cout << "NO\n";
			continue;
		}
		bool ok = 0;
		for (int i = 0; i <= x / 2020; i++)
		{
			if ((x - i * 2020) % 2021 == 0)
			{
				ok = 1;
				break;
			}
		}
		for (int i = 0; i <= x / 2021; i++)
		{
			if ((x - i * 2021) % 2020 == 0)
			{
				ok = 1;
				break;
			}
		}
		cout << (ok==1?"YES\n":"NO\n");
	}

	return 0;
}