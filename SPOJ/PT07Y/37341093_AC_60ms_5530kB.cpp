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
const int N = 1e5;
struct node
{
	bool vis = 0;
	vector<node*>neighbour;
	node()
	{
	}
};
void dfs(node*& curr,node*& par,bool &ok)
{
	curr->vis = 1;
	for (auto it : curr->neighbour)
	{
		if (!it->vis)
			dfs(it, curr, ok);
		else
			if (it != par)
				ok = 0;
	}
}
//dd
int main()
{
	int n, m;
	cin >> n >> m;
	vector<node*>adj(n);
	for (auto& it : adj) it = new node;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u]->neighbour.push_back(adj[v]);
		adj[v]->neighbour.push_back(adj[u]);
	}
	bool ok = 1;
	dfs(adj[0],adj[0], ok);
	for (auto it : adj)
		if (!it->vis)
			return cout << "NO", 0;
	cout << (m == n - 1? "YES\n" : "NO\n");
	return 0;
}