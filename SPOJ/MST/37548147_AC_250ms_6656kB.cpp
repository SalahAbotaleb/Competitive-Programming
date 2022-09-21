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
	if (v->sz < u->sz)
		swap(u, v);
	u->par = v;
	v->sz += u->sz;
	return 1;
}
ll MST(vector<pair<ll, pair<int, int>>> v, vector<node*>& nodes)
{
	ll cost = 0;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		if (connect(nodes[v[i].second.first], nodes[v[i].second.second]))
			cost += v[i].first;
	}
	return cost;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<node*>nodes(n+1);
	vector<pair<ll, pair<int, int>>> v;
	for (int i = 0; i <= n; i++) nodes[i] = new node;
	for (int i = 0; i < m; i++)
	{
		ll x, y, c;
		cin >> x >> y >> c;
		v.push_back({ c ,{x,y} });
	}
	cout << MST(v, nodes) << endl;
	return 0;
}
