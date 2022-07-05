#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
	int idx = -1;
	bool vis = 0;
	int cap = -1;
	int indeg = 0;
	int outdeg = 0;
	vector <Node*> neighbours;
	Node (int _idx):idx(_idx){}
};
struct info
{
	Node* s;
	Node* e;
	int cap;
	info(){}
	info(Node* _s,Node* _e):s(_s),e(_e) {}
};
info bfs(Node*src )
{
	queue<Node*>q;
	q.push(src);
	info ans;
	int cap = src->cap;
	ans.s = src;
	Node* node=NULL;
	while (!q.empty())
	{
	    node = q.front();
		q.pop();
		for(auto&neighbour:node->neighbours)
			if (neighbour->vis == 0)
			{
				neighbour->vis = 1;
				if(neighbour->cap!=-1)
				cap = min(cap, neighbour->cap);
				q.push(neighbour);
			}
	}
	ans.e = node;
	ans.cap = cap;
	return ans;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector <Node*> nodes(n);
	for (int i = 0; i < n; i++) nodes[i] = new Node(i);
	for (int i = 0; i < m; i++)
	{
		int u, v,cap;
		cin >> u >> v >> cap;
		u--, v--;
		nodes[u]->cap = cap;
		nodes[u]->neighbours.push_back(nodes[v]);
		nodes[v]->indeg = 1;
		nodes[u]->outdeg = 1;
	}
	vector <info> ans;
	for (auto& node : nodes)
		if (node->indeg == 0&&node->outdeg==1)
			ans.push_back(bfs(node));
	cout << ans.size() << endl;
	for (auto& show : ans)
		cout << show.s->idx + 1 << " " << show.e->idx + 1 << " " << show.cap << endl;
	return 0;
}