#include <iostream>
#include <vector>
#include <queue>
//#include <bits/stdc++.h>
using namespace std;
struct Node
{
	Node* par = this;
};
/*struct edge
{
	Node* from;
	Node* to;
	edge(Node*f,Node*t):from(f),to(t){}
};*/
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
	
		int n,m1,m2;
		cin >> n>>m1>>m2;
		vector<Node*> nodes1(n);
		vector<Node*> nodes2(n);
		for (auto& node : nodes1) node = new Node;
		for (auto& node : nodes2) node = new Node;
		for (int i = 0; i < m1; i++)
		{
			int f, t;
			cin >> f >> t;
			f--, t--;
			join(nodes1[f], nodes1[t]);
		}
		for (int i = 0; i < m2; i++)
		{
			int f, t;
			cin >> f >> t;
			f--, t--;
			join(nodes2[f], nodes2[t]);
		}
		if (m1 == n - 1 || m2 == n - 1)
		{
			cout << 0 << endl;
			return 0;
		}
		vector <pair<int, int> >ans;
		for(int j=0;j<n;j++)
		for (int i = 0; i < n; i++)
		{
			if (findparent(nodes1[j]) != findparent(nodes1[i]) && findparent(nodes2[j]) != findparent(nodes2[i]))
			{
				join(nodes1[j], nodes1[i]);
				join(nodes2[j], nodes2[i]);
				ans.push_back({ j+1,i + 1 });
			}
		}
		cout << ans.size() << endl;
		for (auto& res : ans)
			cout << res.first << " " << res.second << endl;
	return 0;
}