#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
//#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Node
{
	int id = -1;
	Node* par = this;
	Node* end = this;
	Node* nxt = NULL;
	int sz = 1;
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
		a->end->nxt = b;
		a->end = b->end;
	}

}

int main()
{
	int n;
	cin >> n ;
	vector<Node*> nodes(n);
	for (int i = 0; i < n; i++) nodes[i] = new Node(i+1);
	for (int i = 0; i < n-1; i++)
	{
		int u, v;
		cin >> u >> v ;
		u--, v--;
		join(nodes[u], nodes[v]);
	}
	Node* origin = findparent(nodes[0]);
	while (origin->nxt != NULL)
	{
		cout << origin->id << " ";
		origin = origin->nxt;
	}
	cout << origin->id;
	return 0;

}