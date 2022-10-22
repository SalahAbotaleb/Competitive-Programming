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
	ll dis = loo;
	vector<pair<int, node*> > neighbour;
	node(int id)
	{
		idx = id;
	}
};
void dijkstra(node* src)
{
	priority_queue<pair<ll, node*>, vector<pair<ll, node*>>, greater<pair<ll, node*>>>pq;
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
				neigh->from = curr;
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
	int tc;
	cin >> tc;
	int cnt = 0;
	while (tc--)
	{
		int n, m,s,t;
		cin >> n >> m >>s>>t;
		vector<node*>adj(n);
		for (int i = 0; i < n; i++) adj[i] = new node(i + 1);
		for (int i = 0; i < m; i++)
		{
			int u, v, c;
			cin >> u >> v >> c;
			adj[u]->neighbour.push_back({ c,adj[v] });
			adj[v]->neighbour.push_back({ c,adj[u] });
		}
		dijkstra(adj[s]);
		printf("Case #%d: ", ++cnt);
		if (adj[t]->dis == loo)
		{
			cout << "unreachable\n";
		}
		else
		{
			cout << adj[t]->dis << endl;
		}
	}
	return 0;
}