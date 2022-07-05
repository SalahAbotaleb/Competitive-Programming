#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
	int vis = 0;
	int take = 0;
	int id = -1;
	vector <Node*> neighbours;
	Node(int _id):id(_id){}
};
void bfs(Node*src,vector<int>&vO,vector <int>&vE)
{
	queue<Node*>q;
	q.push(src);
	src->vis = 1;
	while (!q.empty())
	{
		Node* node = q.front();
		q.pop();
		if (node->take == 0)
			vE.push_back(node->id+1);
		if (node->take == 1)
			vO.push_back(node->id + 1);
		for (auto& neighbour : node->neighbours)
		{
			if (neighbour->vis == 0)
			{
				neighbour->vis = 1;
				neighbour->take = 1 - node->take;
				q.push(neighbour);
			}
		}
	}
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m;
		cin >> n >> m;
		vector<Node*>nodes(n);
		for (int i = 0; i < n; i++) nodes[i] = new Node(i);
		while (m--)
		{
			int u, v;
			cin >> u >> v;
			u--, v--;
			nodes[u]->neighbours.push_back(nodes[v]);
			nodes[v]->neighbours.push_back(nodes[u]);
		}
		vector <int> vO;
		vector <int> vE;
		bfs(nodes[0], vO, vE);
		if (vO.size() < vE.size())
		{
			cout << vO.size() << endl;
			for (auto& v : vO)
				cout << v << " ";
		}
		else
		{
			cout << vE.size() << endl;
			for (auto& v : vE)
				cout << v << " ";
		}cout << endl;
	}
	

	return 0;
}