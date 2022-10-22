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
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
ll f_pow(int b, int p)
{
	ll ans = 1;
	while (p > 0)
	{
		if (p & 1)
			ans = (1ll * ans * b) % mod;
		b = (1ll * b * b) % mod;
		p >>= 1;
	}
	return ans % mod;
}
struct node
{
	node* par = this;
	ll sz = 1;
	int mx;
	int color=0;
};
node* fndpar(node* u)
{
	if (u->par == u)
		return u;
	return u->par = fndpar(u->par);
}
bool connect(node* u, node* v)
{
	u = fndpar(u);
	v = fndpar(v);
	if (u == v)
		return 0;
	if (v->sz > u->sz)
	{
		u->par = v;
		v->sz += u->sz;
		v->mx = max(v->mx, u->mx);
	}
	else
	{
		v->par = u;
		u->sz += v->sz;
		u->mx = max(v->mx, u->mx);
	}
	return 1;
}
bool isconnected(node* u, node* v)
{
	return fndpar(u) == fndpar(v);
}
ll MST(vector<pair<ll, pair<int, int>>>& v, vector<node*>& nodes)
{
	ll cost = 0;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		int from = v[i].second.first;
		int to = v[i].second.second;
		if (!isconnected(nodes[from], nodes[to]))
		{
			connect(nodes[from], nodes[to]);
			cost += v[i].first;
		}
	}
	return cost;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<node*>nodes(N);
	for (int i = 0; i < N; i++) nodes[i] = new node, nodes[i]->mx = i;
	vector<pair<pair<int, int>, int>>v;
	for (int i = 0; i < m; i++)
	{
		int u, t, c;
		cin >> u >> t >> c;
		v.push_back({ {u ,t },c });
	}
	while (!v.empty())
	{
		auto it = v.back();
		v.pop_back();
		int from = it.first.first;
		int to = it.first.second;
		int cc = it.second;
		for (int i = from; i <= to; i++)
		{
			
			if (nodes[i]->color)
			{
				i = fndpar(nodes[i])->mx;
			}
			else
				nodes[i]->color = cc,connect(nodes[i], nodes[from]);
		}
	}
		for (int i=1;i<=n;i++) 
			cout << nodes[i]->color << endl;
	return 0;
}
