#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#include <iomanip>
#include <stack>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const ll loo = 0x3f3f3f3f3f3f3f3f;
struct node
{
	int idx = -1;
	bool vis = 0;
	ll dis = loo;
	vector<node*>negihbour;
};
node* bfs(node* src)
{
	queue<node*>q;
	src->dis = 0;
	q.push(src);
	node* l=src;
	while (!q.empty())
	{
		auto curr = q.front();
		int dis = q.front()->dis;
		l = curr;
		q.pop();
		for (auto neigh : curr->negihbour)
		{
			if (dis+1 < neigh->dis)
			{
				neigh->dis = dis+1;
				q.push(neigh);
			}
		}
	}
	return l;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<node*>adj(n);
	for (int i = 0; i < n; i++) adj[i] = new node,adj[i]->idx=i+1;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u]->negihbour.push_back(adj[v]);
		adj[v]->negihbour.push_back(adj[u]);
	}
	node*l=bfs(adj[0]);
	for (auto& it : adj)it->dis = loo;
	cout << bfs(l)->dis << endl;;

	return 0;
}