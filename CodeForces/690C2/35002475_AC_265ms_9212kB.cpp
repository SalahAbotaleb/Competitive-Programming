#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
	bool vis = 0;
	int dis = 0;
	vector <Node*> neighbours;

};
/*void dfs(Node*node,int &mx,int level=0)
{
	node->vis = 1;
	mx = max(mx, level);
	for (auto& neigbour : node->neighbours)
	{
		if (neigbour->vis == 0)
		{
			dfs(neigbour, mx, level + 1);
		}
	}
}*/
Node* bfs(Node* src)
{
	queue<Node*>q;
	q.push(src);
	src->vis = 1;
	src->dis = 0;
	Node* node=q.front();
	while (!q.empty())
	{
		node = q.front();
		q.pop();
		for (auto& neighbour : node->neighbours)
		{
			if (neighbour->vis == 0)
			{
				neighbour->vis = 1;
				neighbour->dis = node->dis + 1;
				q.push(neighbour);
			}
			//cout << node->dis << endl;
		}
	}
	return node;
}
int main()
{
	int n,m;
	cin >> n>>m;
	vector <Node*> nodes(n);
	for (int i = 0; i < n; i++) nodes[i] = new Node;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		nodes[u]->neighbours.push_back(nodes[v]);
		nodes[v]->neighbours.push_back(nodes[u]);
	}
	int mx = 0;
	Node* start = bfs(nodes[0]);;
	
	for (int i = 0; i < n; i++)
		nodes[i]->dis = 0, nodes[i]->vis = 0;
	Node* end= bfs(start);
	

	cout << end->dis << endl;
	return 0;
}