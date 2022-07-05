#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int oo = 0x3f3f3f3f;
struct Node
{
	int dis = oo;
	vector <pair<int, Node*> > neighbours;
};
int Dijkstra(Node* src, Node* target)
{
	priority_queue<pair<int, Node*>,vector<pair<int, Node*>>,greater<pair<int, Node*>>> pq;
	src->dis = 0;
	pq.push({ 0,src });
	while (!pq.empty()) 
	{
		Node* node = pq.top().second;
		int weightSofar = pq.top().first;
		pq.pop();
		if (weightSofar != node->dis)
			continue;
		if (node == target)
			break;
		for (auto& e : node->neighbours)
		{
			auto neighbour = e.second;
			int weight = e.first;
			if (node->dis + weight < neighbour->dis)
			{
				neighbour->dis = node->dis + weight;
				pq.push({ neighbour->dis,neighbour });
			}
		}
	}
	return target->dis;
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m,s,e;
		cin >> n >> m>>s>>e;
		e--, s--;
		vector <Node*> nodes(n);
		for (int i = 0; i < n; i++) nodes[i] = new Node;
		for (int i = 0; i < m; i++)
		{
			int u, v, c;
			cin >> u >> v >> c;
			u--, v--;
			nodes[u]->neighbours.push_back({ c,nodes[v] });
			nodes[v]->neighbours.push_back({ c,nodes[u] });
		}
		int ans = Dijkstra(nodes[s], nodes[e]);
		if (ans == oo)
			cout << "NONE" << endl;
		else
			cout << ans << endl;
	}
	

}