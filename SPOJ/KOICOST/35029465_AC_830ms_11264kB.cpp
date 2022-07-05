#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9;
struct Node
{
	Node* par=this;
	int sz = 1;
};
struct edge
{
	Node* from;
	Node* to;
	int cost = 0;
	edge(Node* f,Node* t,int c):from(f),to(t),cost(c){}
	bool operator <(edge& e2)
	{
		return cost > e2.cost;
	}
};
Node* findparent(Node* node)
{
	if (node->par == node) return node;
	return node->par = findparent(node->par);
}

void join(Node* a, Node* b,ll &currPair)
{
	a = findparent(a);
	b = findparent(b);
	if (a != b)
	{
		currPair = (currPair + ((ll)a->sz * b->sz)%MOD) % MOD;
		b->par = a;
		a->sz += b->sz;
	}
	
}
int main()
{
	int n,m;
	cin >> n >> m;
	vector<Node*> nodes(n);
	for (int i = 0; i < n; i++) nodes[i] = new Node;
	vector<edge> edges;
	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;
		edges.push_back(edge(nodes[u], nodes[v], c));
	}
	sort(edges.begin(),edges.end());
	ll ans = 0;
	ll currP = 0;
	for (int i=0;i<m;i++)
	{
		Node* from = edges[i].from;
		Node* to = edges[i].to;
		int cost = edges[i].cost;
		join(from, to,currP);
	
		ans =(ans%MOD+ ((ll)currP*cost)%MOD)%MOD;
	}
	cout << ans << endl;
	return 0;

}