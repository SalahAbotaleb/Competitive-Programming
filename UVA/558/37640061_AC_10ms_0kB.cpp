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
bool bellman(int src,int sz,vector<pair<int,pair<int,int>>>& list)
{
	vector<ll>dist(sz,loo);
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
	while (tc--)
	{
		int n, m;
		cin >> n >> m;
		vector<pair<int, pair<int, int>>> list;
		for (int i = 0; i < m; i++)
		{
			int u, v, c;
			cin >> u >> v >> c;
			list.push_back({ c,{u,v} });
		}
		cout<<(bellman(0, n, list)?"possible\n":"not possible\n");
	}

	return 0;
}
