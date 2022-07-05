#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct Node
{
	bool vis = 0;
	vector<Node*> neighbours;
};
int dfs(Node* node, int level)
{
	int max = level;
	node->vis = 1;
	if (level > max)
		max = level;
	for (auto& neighbours : node->neighbours)
	{
		int res = dfs(neighbours, level + 1);
		max = res > max ? res : max;
	}
	return max;
}
int main()
{
	int n;
	cin >> n;
	vector <Node*> nodes(n);
	for (auto& node : nodes) node = new Node;
	vector <Node*> roots;
	for (int u = 0; u < n; u++)
	{
		int v;
		cin >> v;
		if (v == -1)
		{
			roots.push_back(nodes[u]);
			continue;
		}
		v--;
		nodes[v]->neighbours.push_back(nodes[u]);
	}
	int max = 0;
	for (auto& node : roots)
	{
		int res=dfs(node, 1);
		max = res > max ? res : max;
	}
		cout << max << endl;
	return 0;
}