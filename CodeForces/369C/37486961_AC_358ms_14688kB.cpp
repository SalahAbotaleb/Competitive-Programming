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
	ll dis = loo;
	bool vis = 0;
	int src = -1;
	int deg = 0;
	vector<pair<node*, int>>negihbour;
};
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool dfs(node* curr, vector<int>& v)
{
	curr->vis = 1;
	bool ok = 0;
	for (auto it : curr->negihbour)
	{
		auto nxt = it.first;
		int stat = it.second;
		if (nxt->vis)
			continue;
		bool down = dfs(nxt, v);
		ok |= down;
		ok |= (stat == 2);
		if (!down && stat == 2)
			v.push_back(nxt->idx);
	}
	return ok;
}
int main()
{
	int n;
	cin >> n;
	vector<node*>adj(n);
	for (int i = 0; i < n; i++) adj[i] = new node, adj[i]->idx = i + 1;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v, stat;
		cin >> u >> v >> stat;
		u--, v--;
		adj[u]->negihbour.push_back({ adj[v] ,stat });
		adj[v]->negihbour.push_back({ adj[u] ,stat });
		adj[u]->deg++, adj[v]->deg++;
	}
	vector<int>v;
	dfs(adj[0], v);
	cout << v.size() << endl;
	for (auto it : v) cout << it << " ";
	return 0;
}