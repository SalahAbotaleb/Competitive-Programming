#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
//#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Node
{
	Node* par=this;
	Node* nxt = NULL;
	int sz = 1;
	int id = -1;
	int total = 0;
	Node(int _id,int _t):id(_id),total(_t) {}
	Node(int _id, int _sz, int _total)
	{
		id = _id;
		sz = _sz;
		total = _total;
	}
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
		a->total += b->total;
	}
	
}
void remove(Node* a, Node* b)
{
	Node* pa = findparent(a);
	if (pa == a && a->sz == 1)
	{
		join(a, b);
		return;
	}
	a->nxt = new Node(a->id, 1,a->id);
	pa->sz--;
	pa->total -= a->id;
	join(a->nxt, b);
}
Node* latest(Node* src)
{
	if (src->nxt == NULL) return src;
	return src->nxt = latest(src->nxt);
}
int main()
{
	int n,m;
	while (cin >> n >> m)
	{
		vector<Node*> nodes(n);
		for (int i = 0; i < n; i++) nodes[i] = new Node(i + 1, i + 1);
		for (int i = 0; i < m; i++)
		{
			int q;
			cin >> q;
			if (q == 1)
			{
				int u, v;
				cin >> u >> v;
				u--, v--;
				join(latest(nodes[u]), latest(nodes[v]));
			}
			if (q == 2)
			{
				int u, v;
				cin >> u >> v;
				u--, v--;
				remove(latest(nodes[u]), latest(nodes[v]));
			}
			if (q == 3)
			{
				int u;
				cin >> u;
				u--;
				//cout << "<--------->" << endl;
				cout << findparent(latest(nodes[u]))->sz << " " << findparent(latest(nodes[u]))->total << endl;
			}
		}
	}
	return 0;

}