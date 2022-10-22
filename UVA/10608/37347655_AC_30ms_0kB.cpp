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
#define ll long long
using namespace std;
const int N = 1e5;
struct node
{
	int id = -1;
	bool vis = 0;
	vector<node*>neighbour;
};
int dfs(node* curr)
{
	curr->vis = 1;
	int cnt = 0;
	for (auto it : curr->neighbour)
	{
		if (it->vis == 0)
			cnt+=1+dfs(it);
	}
	return cnt;
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
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
		int mx = 0;

		for (auto it : adj)
			if (it->vis == 0)
				mx=max(mx,dfs(it));
		cout << mx+1 << endl;
	}
	return 0;
}