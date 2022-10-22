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
#define ll long long
using namespace std;
const ll N = 1e9;
const int loo = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
struct node
{
	int idx;
	node* from = nullptr;
	ll dis = loo;
	vector<pair<int, node*>> neighbour;
	/*node(int id)
	{
		idx = id;
	}*/
};
void dijkstra(node* src)
{
	priority_queue<pair<int, node*>, vector<pair<int, node*>>, greater<pair<int, node*>>>pq;
	src->dis = 0;
	pq.push({ 0,src });
	while (!pq.empty())
	{
		auto curr = pq.top().second;
		ll weight = pq.top().first;
		pq.pop();
		if (weight != curr->dis)
			continue;
		for (auto nxt : curr->neighbour)
		{
			ll nweight = weight + nxt.first;
			node* neigh = nxt.second;
			if (nweight < neigh->dis)
			{
				neigh->dis = nweight;
				pq.push({ nweight,neigh });
			}
		}
	}
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m,st,ed;
		cin >> n >> m >>st>>ed; 
		vector<node*>adj(n);
		for (auto &it : adj) it = new node;
		for (int i = 0; i < m; i++)
		{
			int u, v, c;
			cin >> u >> v >> c;
			u--, v--;
			adj[u]->neighbour.push_back({ c,adj[v] });
			adj[v]->neighbour.push_back({ c,adj[u] });
		}
		dijkstra(adj[st-1]);
		if (adj[ed - 1]->dis != loo)
			cout << adj[ed - 1]->dis << endl;
		else
			cout << "NONE\n";

	}


	return 0;
}