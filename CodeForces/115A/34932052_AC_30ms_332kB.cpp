#include <iostream>
#include <vector>
using namespace std;
struct Node
{
	bool vis = 0;
	vector<Node*> neighbours;
};
void dfs(Node* node, int level, int &max)
{
	node->vis = 1;
	if (level > max)
		max = level;
	for (auto& neighbours : node->neighbours)
	{
			dfs(neighbours, level + 1, max);
	}
}
int main()
{
	int n;
	cin >> n;
	vector <Node*> nodes(n);
	for (auto& node : nodes) node = new Node;
	for (int u = 0; u < n; u++)
	{
		int v;
		cin >> v;
		if (v == -1)
			continue;
		v--;
		nodes[u]->neighbours.push_back(nodes[v]);
	}
	int max = 0;
	for (auto& node : nodes)
			dfs(node, 1,max);
	cout << max << endl;
	return 0;
}