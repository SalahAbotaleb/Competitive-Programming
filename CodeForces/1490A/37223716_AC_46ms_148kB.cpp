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
bool ok(int a, int b)
{
	int mn = min(a, b);
	int mx = max(a, b);
	return (mn + mx - 1) / mn > 2;
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		vector<int>v(n);
		for (auto& x : v) cin >> x;
		int ic = 0;
		int in = 1;
		int cnt = 0;
		while (in < n)
		{
			if (ok(v[ic], v[in]))
			{
				int from = min(v[ic], v[in]);
				int to = max(v[ic], v[in]);
				while (ok(from, to))
				{
					from *= 2;
					cnt++;
				}
			}
			ic++;
			in++;
		}
		cout << cnt << endl;
	}

	return 0;
}