#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
	int id = -1;
	bool vis = 0;
	bool destroy = 0;
	int degree = 0;
	vector <Node*> neighbours;
	Node(int _id) :id(_id) {}
};
int dfs(Node* node, vector <int>& ans)
{
	int noproblem = 1;
	node->vis = 1;
	for (auto& neighbour : node->neighbours)
	{
		if (neighbour->vis == 0)
			noproblem = dfs(neighbour,ans) && noproblem;
	}
	if (noproblem && node->destroy)
		ans.push_back(node->id);
	if (node->destroy)
		noproblem = 0;
	return noproblem;
}
int main()
{
	int n;
	cin >> n;
	vector <Node*> nodes(n);
	for (int i = 0; i < n; i++) nodes[i] = new Node(i + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v, s;
		cin >> u >> v >> s;
		u--, v--;
		nodes[v]->neighbours.push_back(nodes[u]);
		nodes[u]->neighbours.push_back(nodes[v]);
		if (s == 2)
		{
			nodes[v]->destroy = 1;
			nodes[u]->destroy = 1;
		}
	}
	Node* src = nodes[0];
	
	vector <int> ans;
	dfs(src, ans);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " \n"[i == ans.size() - 1];
	return 0;
}