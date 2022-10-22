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
	}
	else
	{
		v->par = u;
		u->sz += v->sz;
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
	for (int i = 0; i < N; i++) nodes[i] = new node;
	for (int i = 0; i < n-1; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		if (c == 0)
			connect(nodes[u], nodes[v]);
	}
	set<node*>s;
	for (int i = 1; i <= n; i++)
	{
		s.insert(findpar(nodes[i]));
	}
	int cnt = f_pow(n, m);
	for (auto it : s)
		cnt = (cnt - f_pow(it->sz,m)+ mod) % mod;
			cout << cnt << endl;
	return 0;
}
