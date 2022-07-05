#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
	Node* par = this;
};
struct edge
{
	Node* from;
	Node* to;
	int weight;
	bool operator < (edge e2)
	{
		return weight < e2.weight;
	}
};
Node* findparent(Node* node)
{
	if (node->par == node) return node;
	return node->par = findparent(node->par);
}
bool join(Node* a, Node* b)
{
	a = findparent(a);
	b = findparent(b);
	if (a != b)
	{
		b->par = a;
		return 1;
	}
	else
		return 0;
}
int kruskall(vector <edge>& edges)
{
	sort(edges.begin(), edges.end());
	int cost = 0;
	for (auto& edge : edges)
		if (join(edge.from, edge.to))
			cost += edge.weight;
	return cost;
}
int main()
{
	int n , m;
	cin >> n >> m;
	vector<Node*> nodes(n);
	vector<edge> edges(m);
	for (auto& node : nodes) node = new Node;
	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		from--, to--;
		edges[i].from = nodes[from];
		edges[i].to = nodes[to];
		edges[i].weight = cost;
	}
	cout << kruskall(edges) << endl;
	return 0;
}