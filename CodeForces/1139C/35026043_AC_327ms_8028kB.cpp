#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
//#include <bits/stdc++.h>
#define ll long long
const int MOD = 1e9 + 7;
using namespace std;
struct Node
{
	Node* par=this;
	int sz = 1;
	int id = -1;
	Node(int _id):id(_id){}
};
Node* findparent(Node* node)
{
	if (node->par == node) return node;
	return node->par = findparent(node->par);
}
void join(Node* a, Node* b)
{
	a = findparent(a);
	b = findparent(b);
	if (a != b)
	{
		b->par = a;
		a->sz += b->sz;
	}
	
}
ll MODpow(ll b, ll p, ll mod)
{
	if (p == 0) return 1;
	ll h = MODpow(b, p / 2, mod);
	return ((h * h) % MOD * (p & 1 ? b : 1) % MOD) % MOD;
}
int main()
{
	int n,m;
	cin >> n >> m;
	vector<Node*> nodes(n);
	for (int i = 0; i < n; i++) nodes[i] = new Node(i);
	for (int i = 0; i < n-1; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;
		if (c == 0)
			join(nodes[u], nodes[v]);
	}
	ll ans = MODpow(n, m, MOD);
	unordered_set<Node*> s;
	for (int i = 0; i < n; i++) s.insert(findparent(nodes[i]));
	for (auto node : s) ans=(ans-MODpow(node->sz,m,MOD)+MOD)%MOD;
	cout << ans << endl;
	return 0;

}