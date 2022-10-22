#include<iostream>
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
#define ll long long
using namespace std;
const int N = 1e5;
struct node
{
	int id = -1;
	bool vis = 0;
	vector<node*>neighbour;
};
void dfs(node* curr, ll& cnt)
{
	curr->vis = 1;
	for (auto it : curr->neighbour)
	{
		if (it->vis == 0)
		{
			cnt *= 2; dfs(it, cnt);
		}
	}
}
int main()
{
	//ofstream fout("test.txt");
	int n, m;
	cin >> n >> m;
	vector<node*>adj(n);
	for (int i = 0; i < n; i++)
	{
		adj[i] = new node;
		adj[i]->id = i + 1;
	}
	for (int i = 0; i < m; i++)
	{
		int v, u;
		cin >> u >> v;
		u--, v--;
		adj[u]->neighbour.push_back(adj[v]);
		adj[v]->neighbour.push_back(adj[u]);
	}
	ll mx = 1;
	stack<int>s;
	for (auto it : adj)
	{
		ll cnt = 1;
		if (!it->vis)
		{
			dfs(it, mx);
		}
	}
	cout << mx << endl;
	return 0;
}