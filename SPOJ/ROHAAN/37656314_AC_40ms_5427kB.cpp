#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <fstream>
#include <cassert>
#include <iomanip> 
#define ll long long
using namespace std;
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
bool bellman(int src, int sz, vector<pair<int, pair<int, int>>>& list)
{
	vector<ll>dist(sz, loo);
	bool iscycl = 0;
	dist[src] = 0;
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < list.size(); j++)
		{
			int from = list[j].second.first;
			int to = list[j].second.second;
			int cost = list[j].first;
			if (dist[from] + cost < dist[to])
			{
				dist[to] = dist[from] + cost;
				if (i == sz - 1)
				{
					iscycl = 1;
				}
			}
		}
	}
	return iscycl;
}
int main()
{
	int tc;
	cin >> tc;
	int cc = 0;
	while (tc--)
	{
		int n;
		cin >> n;
		vector<vector<ll>>dist(n, vector<ll>(n, loo));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> dist[i][j];
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		int k;
		cin >> k;
		ll cnt = 0;
		while (k--)
		{
			int u, v;
			cin >> u >> v;
			u--, v--;
			cnt += dist[u][v];
		}
		cout <<"Case #"<<++cc<<": " << cnt << endl;
	}

	return 0;
}
