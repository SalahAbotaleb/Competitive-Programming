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
const ll N = 1e9;
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
struct node
{
	int idx;
	node* from = nullptr;
	vector<pair<int, node*> > neighbour;
	ll dis = loo;
	node(int id)
	{
		idx = id;
	}
};
void dijkstra(int src, vector<vector<ll>>&grid,vector<node*>&adj)
{
	priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll,int>>>pq;
	grid[src][src] = 0;
	pq.push({ 0,src });
	while (!pq.empty())
	{
		auto curr = pq.top().second;
		ll weight = pq.top().first;
		pq.pop();
		if (weight != grid[src][curr])
			continue;
		for (auto nxt : adj[curr]->neighbour)
		{
			ll nweight = weight + nxt.first;
			int neigh = nxt.second->idx;
			if (nweight < grid[src][neigh])
			{
				grid[src][neigh] = nweight;
				pq.push({ nweight,neigh });
			}
		}
	}
}
void rst(vector<node*>& v)
{
	for (auto& it : v) it->dis = loo, it->from = nullptr;
}
int main()
{
	int tc=1;
	int cnt = 0;
	while (tc--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		vector<node*>adj(n);
		vector<vector<ll>>grid(n, vector<ll>(n, loo));
		vector<pair<int, int>> list;
		vector<pair<int, int>> edges;
		for (int i = 0; i < n; i++) adj[i] = new node(i);
		for (int i = 0; i < m; i++)
		{
			int u, v, c;
			cin >> u >> v >> c;
			u--, v--;
			adj[u]->neighbour.push_back({ c,adj[v] });
			adj[v]->neighbour.push_back({ c,adj[u] });
			edges.push_back({ u,v });
		}
		for (int i = 0; i < k; i++)
		{
			int u, v;
			cin >> u >> v;
			u--, v--;
			list.push_back({ u,v });

		}
		ll cst = INT_MAX;
		for (int i = 0; i <n; i++)
		{
			dijkstra(i, grid,adj);
		}
		for (int i = 0; i < edges.size(); i++)
		{
			ll ans = 0;
			for (int j = 0; j < list.size(); j++)
			{
				ll a1= (grid[list[j].first][edges[i].first] + grid[edges[i].second][list[j].second]);
				ll a2= (grid[list[j].first][edges[i].second] + grid[edges[i].first][list[j].second]);
				ans += min({ a1, a2, grid[list[j].first][list[j].second]});
			}
			cst = min(cst, ans);
		}
		cout << cst << endl;
	}
	return 0;
}