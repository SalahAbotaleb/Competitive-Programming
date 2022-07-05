#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
	bool vis = 0;
	int color = 0;
	int pc = 0;
	int degree = 0;
	int id = -1;
	vector <Node*> neighbours;
	Node (int _id):id(_id){}
};
int getcolor( int sz,int start_idx ,int pc, int gfc)
{
	int id = start_idx;
	//cout <<"szzzz" << sz << endl;
	while (true)
	{
		id++;
		//cout << id << endl;
		if (id == gfc || id==pc )
			continue;
		if (id >= sz)
		{
			id = 0;
			if (id == gfc || id == pc)
				continue;
		}
		return id;
	}
}

void bfs(Node* src,int sz)
{
	queue<Node*>q;
	q.push(src);
	src->vis = 1;
	while (!q.empty())
	{
		Node* node = q.front();
		q.pop();
		int idx = 0;
		for (auto& neighbour : node->neighbours)
		{
			if (neighbour->vis == 0)
			{
				//cout << neighbour->id << "  " << idx << endl;
				neighbour->vis = 1;
				neighbour->pc = node->color;
				neighbour->color = getcolor(sz, idx, node->color, node->pc);
				idx = neighbour->color;
				q.push(neighbour);
			}
			
		}
	}
}
int main()
{
	int n;
	int mxD = 0;
	cin >> n;
	vector <Node*> nodes(n);
	for (int i = 0; i < n; i++) nodes[i] = new Node(i+1);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		nodes[u]->neighbours.push_back(nodes[v]);
		nodes[v]->neighbours.push_back(nodes[u]);
		nodes[u]->degree++;
		nodes[v]->degree++;
		mxD = max(mxD,max(nodes[u]->degree, nodes[v]->degree));
	}
	bfs(nodes[0], mxD + 1);
	cout << mxD + 1 << endl;
	for (auto& node : nodes)
		cout << node->color+1 << " ";

	return 0;
}