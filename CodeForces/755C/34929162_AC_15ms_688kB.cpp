#include <iostream>
#include <vector>
using namespace std;
struct Node
{
	bool vis = 0;
	vector <Node*> neihbours;
};
void dfs(Node* node)
{
	node->vis = 1;
	for (auto& neghibour : node->neihbours)
	{
		if (neghibour->vis == 0)
			dfs(neghibour);
	}
}
int main()
{
	int n;
	cin >> n;
	vector <Node*> nodes(n);
	for (int i = 0; i < n; i++) nodes[i] = new Node;
	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		v--;
		nodes[i]->neihbours.push_back(nodes[v]);
		nodes[v]->neihbours.push_back(nodes[i]);
	}
	int cnt = 0;
	for (auto& node : nodes)
	{
		if (node->vis == 0)
		{
			cnt++;
			dfs(node);
		}
	}
	cout << cnt << endl;
	return 0;
}