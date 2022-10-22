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
struct node
{
	node* par = this;
	int sz = 1;
	int mx;
};
/*void intial(int* par, int* sz)
{
	for (int i = 0; i <= N; i++)
		par[i] = i, sz[i] = 1;
}
int findpar(int* par, int u)
{
	if (par[u] == u)
		return u;
	return par[u] = findpar(par, par[u]);
}
void connect(int u, int v, int* par, int* sz)
{
	u = findpar(par, u);
	v = findpar(par, v);
	if (u == v)
		return;
	if (sz[u] > sz[v])
		par[v] = u, sz[u] += sz[v];
	else
		par[u] = v, sz[v] += sz[u];
}
bool iscon(int u, int v, int* par)
{
	return (findpar(par, u) == findpar(par, v));
}*/
node* findpar(node* u)
{
	if (u->par == u)
		return u;
	return u->par = findpar(u->par);
}
bool isconnected(node* u, node* v)
{
	return findpar(u) == findpar(v);
}
void connect(node* u, node* v)
{
	u = findpar(u);
	v = findpar(v);
	if (u == v)
		return;
	if (u->sz < v->sz)
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
}

/*int MST(int* par, int* sz, vector<pair<int, pair<int, int>>>& lst)
{
	sort(lst.begin(), lst.end());
	int cost = 0;
	for (int i = 0; i < lst.size(); i++)
	{
		int u = lst[i].second.first;
		int v = lst[i].second.second;
		int c = lst[i].first;
		if (!iscon(u, v, par))
		{
			cost += c;
			connect(u, v, par, sz);
		}
	}
	return cost;
}*/
int main()
{
	int n, m;
	cin >> n >> m;
	vector<node*>nodes(N);
	for (int i = 1; i < N; i++) nodes[i] = new node, nodes[i]->mx = i;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		connect(nodes[u], nodes[v]);
	}
	int cnt = 0;
	for (int i = 1; i < N;)
	{
		bool ok = 1;
		int j = i + 1;
			while( j <= findpar(nodes[i])->mx)
			{
				if (!isconnected(nodes[i], nodes[j]))
					connect(nodes[i], nodes[j]),cnt++;
				j++;
			}
			ok = 0;
		i = findpar(nodes[i])->mx + 1;
	}
	cout << cnt << endl;
	return 0;
}
