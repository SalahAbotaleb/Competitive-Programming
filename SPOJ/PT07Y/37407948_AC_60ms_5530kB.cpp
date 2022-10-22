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
void bfs(node* src)
{
	queue<node*>q;
	src->vis = 1;
	q.push(src);
	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();
		for (auto neigh : curr->negihbour)
		{
			if (neigh->vis == 0)
			{
				neigh->vis = 1;
				q.push(neigh);
			}
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<node*>adj(n);
	for (auto& it : adj) it=new node;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u]->negihbour.push_back(adj[v]);
		adj[v]->negihbour.push_back(adj[u]);
	}
	bfs(adj[0]);
	if (m != n - 1)
		return cout << "NO\n", 0;
	for (int i = 0; i < n; i++)
	{
		if(!adj[i]->vis)
		  return cout << "NO\n", 0;
	}
	cout << "YES\n";
	return 0;
}