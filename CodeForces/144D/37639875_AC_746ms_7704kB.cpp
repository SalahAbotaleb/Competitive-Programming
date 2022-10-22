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
struct node
{
	int idx;
	node* from = nullptr;
	ll dis = loo;
	vector<pair<int, node*>> neighbour;
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
			else
			{
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
	int n, m, t;
	cin >> n >> m >> t;
	vector<node*>adj(n);
	for (int i = 0; i < n; i++) adj[i] = new node(i);
	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;
		adj[u]->neighbour.push_back({ c,adj[v] });
		adj[v]->neighbour.push_back({ c,adj[u] });
	}
	int k;
	cin >> k;
	int cnt = 0;
	dijkstra(adj[t - 1]);
	for (auto curr : adj)
		if (curr->dis == k)
			cnt++;
	set<pair<int, int>>s;
	for (auto& curr : adj)
	{
		for (auto& child : curr->neighbour)
		{
			int l = child.first;
			int seglen = k - curr->dis;
			if (curr->dis < k && curr->dis + child.first > k)
			{
				if (s.find({ curr->idx,child.second->idx }) != s.end() || s.find({ child.second->idx, curr->idx }) != s.end())
					continue;
				if (k == (l - seglen) + child.second->dis)
					s.insert({ curr->idx,child.second->idx }), cnt++;
				else
					if (k < (l - seglen) + child.second->dis)
						cnt++;

			}
		}
	}
	cout << cnt << endl;
	//ee
	return 0;
}