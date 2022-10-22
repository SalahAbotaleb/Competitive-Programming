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
	int deg = 0;
	int color=-1;
	vector<node*>negihbour;
};
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
void bfs(node* src,int v)
{
	queue<pair<node*, int>>q;
	q.push({src,-1});
	src->color = 0;
	while (!q.empty())
	{
		auto curr = q.front().first;
		int pc = q.front().second;
		q.pop();
		int nxt = curr->color;
		for (auto& it : curr->negihbour)
		{
			if (it->color != -1)
				continue;
			nxt = (nxt + 1) % v;
			if (nxt == pc)
				nxt = (nxt + 1) % v;
			it->color = nxt;
			q.push({ it,curr->color });
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<node*>adj(n);
	for (int i = 0; i < n; i++) adj[i] = new node;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u]->negihbour.push_back(adj[v]);
		adj[v]->negihbour.push_back(adj[u]);
		adj[u]->deg++, adj[v]->deg++;
	}
	node* mx=nullptr;
	int val=0;
	for (auto it : adj)
	{
		if (it->deg > val)
		{
			mx = it;
			val = it->deg;
		}
	}
	bfs(mx, val+1);
	cout << val + 1 << endl;
	for (auto it : adj) cout << it->color+1 << " ";
	return 0;
}