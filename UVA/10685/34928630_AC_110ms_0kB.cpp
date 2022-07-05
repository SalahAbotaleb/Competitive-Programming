#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct node
{
	bool vis = 0;
	int idx;
	vector<node*> neghibour;
	node(int _idx) :idx(_idx) {}
};
void dfs(node* Node,int &res)
{
	Node->vis = 1;
	res++;
	for (auto& neighbours : Node->neghibour)
	{
		if (neighbours->vis == 0)
		{
			dfs(neighbours, res);
		}
	}
}
int mx(vector<node*>nodes)
{
	int max = 0;
	for (auto& node : nodes)
	{
		if (node->vis == 0)
		{
			int dfsres = 0;
			dfs(node, dfsres);
			max = max < dfsres ? dfsres : max;
		}
	}
	return max;
}
int main()
{
	int n, m;
	while (cin >> n >> m, n+m!=0)
	{
		vector <node*> nodes(n);
		unordered_map <string, int> mp;

		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			mp[s] = i;
		}
		for (int i = 0; i < n; i++) nodes[i] = new node(i);
		for (int i = 0; i < m; i++)
		{
			string u, v;
			cin >> u >> v;
			nodes[mp[u]]->neghibour.push_back(nodes[mp[v]]);
			nodes[mp[v]]->neghibour.push_back(nodes[mp[u]]);
		}
		cout << mx(nodes) << endl;

	}
}