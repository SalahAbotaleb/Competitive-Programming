#include <iostream>
#include <vector>
using namespace std;
struct node
{
	int id = -1;
	int color = -1;
	bool vis = 0;
	vector<node*> neghibour;
	node(int _id) :id(_id) {};
};
bool dfs(node* Node)
{
	Node->vis = 1;
	bool valid = 1;
	for (auto& neighbours : Node->neghibour)
	{
		if (neighbours->vis == 0)
		{
			neighbours->color = 1 - Node->color;
			valid = valid && dfs(neighbours);//accumlative 
		}
		else
			if (neighbours->color == Node->color)
				valid=0;
	}
	return valid;
}
bool valid(vector<node*>nodes)
{
	for (auto& node : nodes)
	{
		if (node->vis == 0)
		{
			node->color = 0;
			if (dfs(node) == 0)
				return 0;
		}
	}
	return 1;
}
int main()
{
	int tc;
	cin >> tc;
	for(int j=0;j<tc;j++)
	{
		int n, m;
		cin >> n >> m;
		vector <node*> nodes(n);
		for (int i = 0; i < n; i++) nodes[i] = new node(i + 1);
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			u--, v--;
			nodes[u]->neghibour.push_back(nodes[v]);
			nodes[v]->neghibour.push_back(nodes[u]);
		}
		printf("Scenario #%d:\n", j + 1);
		if (valid(nodes))
			cout << "No suspicious bugs found!\n";
		else
			cout << "Suspicious bugs found!\n";
	}
}
