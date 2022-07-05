#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
const ll lOO = 0x3f3f3f3f3f3f3f3f;
struct Node
{
	int id = -1;
	ll cost = lOO;
	vector <pair<ll, Node*>> neighbours;
};
void dijkstra(Node* src)
{
	priority_queue <pair<ll, Node*>,vector<pair<ll,Node*>>,greater<pair<ll, Node*>>> q;
	src->cost = 0;
	q.push({ 0,src });
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
	
	
		int n, m ,q;
		cin >> n >> m >>q;
		vector <Node*> nodes(n);
		for (int i = 0; i < n;i++) nodes[i] = new Node, nodes[i]->id = i;
		for (int i = 0; i < m; i++)
		{
			int u, v;
			ll c;
			cin >> u >> v >> c;
			nodes[u]->neighbours.push_back({ c,nodes[v] });
			nodes[v]->neighbours.push_back({ c,nodes[u] });
		}
		for (int i = 0; i < q; i++)
		{
			for (int j = 0; j < n; j++) nodes[j]->cost = lOO;
			int s;
			cin >> s;
			int cnt = 0;
			dijkstra(nodes[s]);
			ll mx = 0;
			for (auto& node : nodes)
				if (node->cost != lOO)
					mx = max(node->cost, mx);
			for (auto& node : nodes)
				if (node->cost == mx)
					cnt++;
			cout <<mx << " " << cnt << endl;
		}
		
}