#include <iostream>
#include <vector>
#include <queue>
//#include <bits/stdc++.h>
using namespace std;
struct Node
{
	Node* par = this;
	int id = -1;
	Node(int _id):id(_id){}
};
struct edge
{
	Node* from;
	Node* to;
	edge(Node*f,Node*t):from(f),to(t){}
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
		if (a->id < b->id) swap(a, b);
		b->par = a;
	}
}
/*int kruskall(vector <edge>& edges)
{
	sort(edges.begin(), edges.end());
	int cost = 0;
	for (auto& edge : edges)
		if (join(edge.from, edge.to))
			cost += edge.weight;
	return cost;
}*/
int main()
{
	int n, m;
	cin >> n >> m;
	vector<Node*> nodes(n);
	for (int i = 0; i < n; i++) nodes[i] = new Node(i);
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		int f, t;
		cin >> f >> t;
		f--, t--;
		join(nodes[f], nodes[t]);
	}
	for (int i = 0; i < n;)
	{
		int mx = nodes[i]->par->id;
		for (int j = i+1; j < mx; j++)
		{
			if (findparent(nodes[i]) != findparent(nodes[j]))
				join(nodes[i], nodes[j]), cnt++;
		}
		i = max(i + 1, mx);
	}
	
	cout<<cnt<<endl;
	
	return 0;
}