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
ll dijkstra(Node* src,Node* target)
{
	priority_queue <pair<ll, Node*>,vector<pair<ll,Node*>>,greater<pair<ll, Node*>>> q;
	src->cost = 0;
	q.push({ 0,src });
	while (!q.empty())
	{
		Node* node = q.top().second;
		ll weightSofar = q.top().first;
		q.pop();
		if (node == target)
			break;
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
	return target->cost;
}
int main()
{
	int tc;
	cin >> tc;
	for (int j = 0; j < tc; j++)
	{
		int n, m ,s , t;
		cin >> n >> m >> s >> t;
		vector <Node*> nodes(n);
		for (auto& node : nodes) node = new Node;
		for (int i = 0; i < m; i++)
		{
			int u, v;
			ll c;
			cin >> u >> v >> c;
			nodes[u]->neighbours.push_back({ c,nodes[v] });
			nodes[v]->neighbours.push_back({ c,nodes[u] });
		}
		ll ans = dijkstra(nodes[s], nodes[t]);
		printf("Case #%d: ", j + 1);
		if (ans == lOO)
			cout << "unreachable" << endl;
		else
			cout << ans << endl;
	}
}