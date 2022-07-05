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
int max_friends(vector<node*>nodes)
{
	int max = 0;
	for (auto& node : nodes)
	{
		if (node->vis == 0)
		{
			int dfsres=0;
			dfs(node,dfsres);
			max = max < dfsres ? dfsres : max;
		}
	}
	return max;
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
		cout << max_friends(nodes)<<endl;
	}
}
