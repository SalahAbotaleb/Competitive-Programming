#include <iostream>
#include <vector>
//https://vjudge.net/problem/SPOJ-PT07Y
using namespace std;
struct node
{
	int id = -1;
	bool vis = 0;
	vector<node*> neghibour;
	node(int _id) :id(_id) {};
};
void dfs(node* Node)
{
	Node->vis = 1;
	for (auto& neighbours : Node->neghibour)
	{
		if (neighbours->vis == 0)
			dfs(neighbours);
	}
}
bool tree(vector<node*>nodes, int n, int m)
{
	if (m != n - 1)
		return 0;
	dfs(nodes.front());
	for (auto& node : nodes)
	{
		if (node->vis == 0)
			return 0;
	}
	return 1;
}
int main()
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
	if (tree(nodes, n, m))
		cout << "YES\n";
	else
		cout << "NO\n";
}
