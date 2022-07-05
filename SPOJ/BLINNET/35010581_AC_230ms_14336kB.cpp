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
	edge(Node*f,Node*t,int c):from(f),to(t),weight(c){}
	bool operator < (edge& e2)
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
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		vector<Node*> nodes(n);
		vector<edge> edges;
		for (auto& node : nodes) node = new Node;
		for (int i = 0; i < n; i++)
		{
			int  to, cost,m;
			string s;
			cin >> s;
			cin >> m;
			for (int j = 0; j < m; j++)
			{
				cin >> to >> cost;
				to--;
				edges.push_back(edge(nodes[i], nodes[to], cost));
			}
		
		}
		cout << kruskall(edges) << endl;
	}
	return 0;
}