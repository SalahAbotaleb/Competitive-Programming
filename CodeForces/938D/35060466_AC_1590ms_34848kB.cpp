#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
const ll lOO = 0x3f3f3f3f3f3f3f3f;
struct Node
{
	ll cost = lOO;
	vector <pair<ll, Node*>> neighbours;
};
void dijkstra(vector<Node*>&nodes)
{
	priority_queue <pair<ll, Node*>,vector<pair<ll,Node*>>,greater<pair<ll, Node*>>> q;
	for (int i = 0; i < nodes.size(); i++)
		q.push({ nodes[i]->cost,nodes[i] });
	while (!q.empty())
	{
		Node* node = q.top().second;
		ll weightSofar = q.top().first;
		q.pop();
		if (weightSofar != node->cost)
			continue;
		for (auto e : node->neighbours)
		{
			ll weight = e.first;
			Node* to = e.second;
			if (weight + node->cost < to->cost)
			{
				to->cost = weight + node->cost;
				q.push({ to->cost,to });
			}
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector <Node*> nodes(n);
	for (auto& node : nodes) node = new Node;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		ll c;
		cin >> u >> v >> c;
		u--, v--;
		nodes[u]->neighbours.push_back({2*c,nodes[v]});
		nodes[v]->neighbours.push_back({ 2*c,nodes[u]});
	}
	for (int i = 0; i < n; i++) cin >> nodes[i]->cost;
	dijkstra(nodes);
	for (int i = 0; i < n; i++) cout << nodes[i]->cost << " ";

}