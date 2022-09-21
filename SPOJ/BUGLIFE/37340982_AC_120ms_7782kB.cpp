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
	int color = -1;
	node()
	{
	}
};
void dfs(node*& curr,bool &ok,int color)
{
	curr->vis = 1;
	curr->color = color;
	for (auto it : curr->neighbour)
	{
		if (!it->vis)
			dfs(it,ok,1-color);
		else
			if (it->color != 1-color)
				ok = 0;
	}
}
int main()
{
	int n, m;
	int tc;
	cin >> tc;
	int c = 0;
	while (tc--)
	{
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
		for(auto it:adj)
			if(!it->vis)
			dfs(it, ok, 0);
		printf("Scenario #%d:\n", ++c);
		cout << (ok ? "No suspicious bugs found!\n" : "Suspicious bugs found!\n");
	}
	return 0;
}