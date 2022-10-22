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
	bool vis = 0;
	int idx = 0;
	int deg = 0;
	vector<pair<node*, int>> edge;
};
void dfs(node* src, vector<int>& ans, vector<int>& vis)
{
	src->vis = 1;
	while (!src->edge.empty())
	{
		node* to = src->edge.back().first;
		int idx = src->edge.back().second;
		src->edge.pop_back();
		if (vis[idx])
			continue;
		vis[idx] = 1;
		dfs(to, ans, vis);
	}
	ans.push_back(src->idx);
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<node*> nodes(n);
		for (int i = 0; i < n; i++)
		{
			nodes[i] = new node;
			nodes[i]->idx = i;
		}
		if (m == 0)
		{
			cout << "Not Possible\n";
			continue;
		}
		vector<int>vis(m, 0);
		vector<int>ans;
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			nodes[u]->edge.push_back({ nodes[v],i });
			nodes[v]->edge.push_back({ nodes[u],i });
			nodes[u]->deg++;
			nodes[v]->deg++;
		}
		bool ok = 1;
		int beg = 0;
		for (auto it : nodes)
		{
			if (it->deg % 2 == 1)
				ok = 0;
			else
				if (it->deg != 0)
					beg = it->idx;
		}
		dfs(nodes[beg], ans, vis);
		if (ans.size() != m + 1)
			ok = 0;
		cout << (ok ? "Possible\n" : "Not Possible\n");
	}
	return 0;
}