#include <iostream>
#include <vector>
using namespace std;
struct Node
{
	int intial=0;
	int goal = 0;
	bool vis = 0;
	int id=-1;
	vector <Node*> neihbours;
	Node(int _id) :id(_id) {}
};
void dfs(Node* node,int oddcnt,int evencnt,int level ,vector <int>&arr)
{
	node->vis = 1;
	if (level & 1) node->intial = (oddcnt & 1) ? !(node->intial) : node->intial;
	else node->intial=(evencnt&1)? !(node->intial) : node->intial;
	if (node->intial != node->goal)
	{
		if (level & 1) oddcnt++;
		else
			evencnt++;
		arr.push_back(node->id);
	}
	for (auto& neghibour : node->neihbours)
	{
		if (neghibour->vis == 0)
			dfs(neghibour, oddcnt,evencnt,level+1,arr);
	}
}
int main()
{
	int n;
	cin >> n;
	vector <Node*> nodes(n);
	for (int i = 0; i < n; i++) nodes[i] = new Node(i+1);
	for (int i = 0; i < n-1; i++)
	{
		int u,v;
		cin >>u>> v;
		u--,v--;
		nodes[u]->neihbours.push_back(nodes[v]);
		nodes[v]->neihbours.push_back(nodes[u]);
	}
	for (int i = 0; i < n; i++) cin >> nodes[i]->intial;
	for (int i = 0; i < n; i++) cin >> nodes[i]->goal;
	vector<int> ids;
	dfs(nodes[0], 0, 0, 0, ids);
	cout << ids.size() << endl;
	for (int i = 0; i < ids.size(); i++)
		cout << ids[i] << endl;
	return 0;
}