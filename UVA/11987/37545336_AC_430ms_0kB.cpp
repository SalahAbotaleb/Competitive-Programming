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
	return ans%mod;
}
struct node
{
	node* par = this;
	int sz = 1;
	int tot = 0;
	bool ok = 1;
};
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
		v->tot += u->tot;
	}
	else
	{
		v->par = u;
		u->sz += v->sz;
		u->tot += v->tot;
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
	while (cin >> n >> m)
	{
		vector<node*>nodes(n + 1);
		for (int i = 1; i <= n; i++) nodes[i] = new node, nodes[i]->tot = i;
		for (int i = 0; i < m; i++)
		{
			int u, v, c;
			cin >> c;
			if (c == 3)
			{
				cin >> u;
				cout << findpar(nodes[u])->sz << " " << findpar(nodes[u])->tot << endl;
			}
			if (c == 1)
			{
				cin >> u >> v;
				if (isconnected(nodes[u], nodes[v]))
					continue;
				connect(nodes[u], nodes[v]);
			}
			if (c == 2)
			{
				cin >> u >> v;
				if (isconnected(nodes[u], nodes[v]))
					continue;
				findpar(nodes[u])->par->sz--;
				findpar(nodes[u])->par->tot -= u;
				nodes[u] = new node;
				nodes[u]->tot = u;
				connect(nodes[u], nodes[v]);
			}
		}
	}
	return 0;
}
