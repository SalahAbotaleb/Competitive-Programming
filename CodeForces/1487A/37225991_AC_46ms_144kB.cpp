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
		map<int,int>mp;
		for (int i = 0; i < n; i++)
		{
			int x; cin >> x;
			mp[x]++;
		}
		if (mp.size() == 1)
			cout << 0 << endl;
		else
		{
			int cnt = 0;
			auto it = mp.begin();
			it++;
			for (; it != mp.end(); it++)
				cnt += it->second;
			cout << cnt << endl;
		}
	}

	return 0;
}