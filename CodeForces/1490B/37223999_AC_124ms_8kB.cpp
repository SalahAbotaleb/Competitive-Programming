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
		int arr[3]={ };
		int val = n / 3;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			arr[x % 3]++;
		}
		int cnt = 0;
		pair<int, int> pre[3] = { {2,1},{0,2},{1,0} };
		for(int i=0;i<3;i++)
		if (arr[i] < val)
		{
			int i1 = pre[i].first;
			int i2 = pre[i].second;
			int hm = val - arr[i];
			if (arr[i1] > val)
			{
				cnt += (min(hm, arr[i1]-val));
				hm -= (min(hm, arr[i1] - val));
				arr[i1] -= (min(hm, arr[i1] - val));
			}
			if (hm > 0)
			{
				cnt += (min(hm, arr[i2] - val)) * 2;
				hm -= (min(hm, arr[i2] - val));
				arr[i2] -= (min(hm, arr[i2] - val));
			}
		}
		cout << cnt << endl;
	}

	return 0;
}