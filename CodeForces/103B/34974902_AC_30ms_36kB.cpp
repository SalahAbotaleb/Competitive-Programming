#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
	bool vis = 0;
	vector <Node*> neighbours;
};
void BFS(Node* src)
{
	queue<Node*> q;
	q.push(src);
	src->vis = 1;
	while (!q.empty())
	{
		auto node = q.front();
		q.pop();
	
		for (auto neighbour : node->neighbours)
		{
			if (neighbour->vis == 0)
			{
				neighbour->vis = 1;
				q.push(neighbour);
			}
		}
	}
}
bool isTree(vector<Node*> Nodes,int m)
{
	if (Nodes.size()!= m)
	{
		return 0;
	}
	BFS(Nodes.front());
	for (auto node : Nodes)
		if (node->vis == 0)
			return 0;
	return 1;
}
int main()
{

	int n, m;
	cin >> n >> m;
	vector <Node*> nodes(n);
	for (auto &node : nodes) node = new Node;
	for(int i=0;i<m;i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		nodes[u]->neighbours.push_back(nodes[v]);
		nodes[v]->neighbours.push_back(nodes[u]);
	}
	if (isTree(nodes,m))
		cout << "FHTAGN!" << endl;
	else
		cout << "NO" << endl;

}