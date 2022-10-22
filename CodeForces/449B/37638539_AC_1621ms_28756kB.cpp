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
	vector<pair<int,pair< node*,int>> > neighbour;
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
			node* neigh = nxt.second.first;
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
	int n, m,t;
	cin >> n >> m >>t;
	vector<node*>adj(n);
	for (int i = 0; i < n; i++) adj[i] = new node(i);
	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;
		adj[u]->neighbour.push_back({ c,{adj[v],0} });
		adj[v]->neighbour.push_back({ c,{adj[u],0} });
	}
	dijkstra(adj[0]);      
	for (int i = 0; i < t; i++)
	{
		int v,c;
		cin >> v >> c;
		v--;
		adj[0]->neighbour.push_back({ c,{adj[v],1} });
		adj[v]->neighbour.push_back({ c,{adj[0],1 } });
	}
	int istrain[100000] = { };
	int isroute[100000] = { };
	dijkstra(adj[0]);
	for (auto curr : adj)
	{
		for (auto child : curr->neighbour)
		{
			if (child.second.first->dis == curr->dis + child.first)
			{
				if (child.second.second == 1)
					istrain[child.second.first->idx] = 1;
				else
					isroute[child.second.first->idx] = 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (istrain[i] && !isroute[i])
			cnt++;
	cout << t - cnt << endl;
	return 0;
}