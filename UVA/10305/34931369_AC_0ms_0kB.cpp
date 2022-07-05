#include <iostream>
#include <vector>
using namespace std;
struct node
{
	int id = -1;
	bool vis = 0;
	vector<node*> neghibour;
	node(int _id) :id(_id) {};
};
void dfs(node* Node,vector <int> &ids)
{
	Node->vis = 1;
	for (auto& neighbours : Node->neghibour)
	{
		if (neighbours->vis == 0)
			dfs(neighbours,ids);
	}
	ids.push_back(Node->id);
}
int main()
{
	int n, m;
	while (cin >> n >> m && n + m)
	{
		vector <node*> nodes(n);
		for (int i = 0; i < n; i++) nodes[i] = new node(i + 1);
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			u--, v--;
			nodes[v]->neghibour.push_back(nodes[u]);
		}
		vector <int> ids;
		for (auto& node : nodes)
		{
			if (node->vis == 0)
				dfs(node, ids);
		}
		for (int i = 0; i < n; i++)
			cout << ids[i] << " \n"[i == n - 1];

	}
}