#include <iostream>
#include <vector>

using namespace std;
struct node
{
	int id = -1;
	bool vis = 0;
	bool instack = 0;
	vector<node*> neghibour;
	node(int _id) :id(_id) {};
};
bool dfs(node* Node,vector <node*>&stack)
{
	Node->vis = 1;
	Node->instack = 1;
	bool valid = 1;
	for (auto& neighbours : Node->neghibour)
	{
		if (neighbours->vis == 0)
			valid = dfs(neighbours, stack) && valid ;
		else
			if (neighbours->instack == 1)
				valid = 0;
	}
	Node->instack = 0;
	stack.push_back(Node);
	return valid;
}

int main()
{
	int n, m;
	while (cin >> n >> m, n || m)
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
		vector <node*> stack;
		bool valid = 1;
		for(auto &nodes:nodes)
			if(nodes->vis==0)
			valid &= dfs(nodes, stack);
		if (valid)
		{
			for (auto* obj : stack)
			{
				cout << obj->id << endl;
			}
		}
		else
			cout << "IMPOSSIBLE\n";
		
	}
}
