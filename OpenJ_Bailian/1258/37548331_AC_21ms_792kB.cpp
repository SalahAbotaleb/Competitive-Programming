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
	}
	else
	{
		v->par = u;
		u->sz += v->sz;
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
		if (!isconnected(nodes[from],nodes[to]))
		{
			connect(nodes[from], nodes[to]);
			cost += v[i].first;
		}
	}
	return cost;
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<node*>nodes(n);
		vector<pair<ll, pair<int, int>>> v;
		for (int i = 0; i < n; i++) nodes[i] = new node;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				ll x;
				cin >> x;
				v.push_back({ x ,{i,j} });
			}
		cout << MST(v, nodes) << endl;
	}
	return 0;
}
