#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define ll long long
using namespace std;
const int oo = 0x3f3f3f3f;
const ll loo = 0x3f3f3f3f3f3f3f3f;
struct Node
{
	int id = -1;
	ll dis = loo;
	Node* from = NULL;
	vector <pair<ll, Node*> > neighbours;
	Node(int _id):id(_id){}
};
ll Dijkstra(Node* src, Node* target)
{
	priority_queue<pair<ll, Node*>,vector<pair<ll, Node*>>,greater<pair<ll, Node*>>> pq;
	src->dis = 0;
	pq.push({ 0,src });
	while (!pq.empty()) 
	{
		Node* node = pq.top().second;
		ll weightSofar = pq.top().first;
		pq.pop();
		if (weightSofar != node->dis)
			continue;
		if (node == target)
			break;
		for (auto& e : node->neighbours)
		{
			auto neighbour = e.second;
			ll weight = e.first;
			if (node->dis + weight < neighbour->dis)
			{
				neighbour->dis = node->dis + weight;
				pq.push({ neighbour->dis,neighbour });
				neighbour->from = node;
			}
		}
	}
	return target->dis;
}
int main()
{

		int n, m;
		cin >> n >> m;
		vector <Node*> nodes(n);
		for (int i = 0; i < n; i++) nodes[i] = new Node(i+1);
		for (int i = 0; i < m; i++)
		{
			int u, v;
			ll c;
			cin >> u >> v >> c;
			u--, v--;
			nodes[u]->neighbours.push_back({ c,nodes[v] });
			nodes[v]->neighbours.push_back({ c,nodes[u] });
		}
		vector <int> v;
		ll ans = Dijkstra(nodes[0], nodes[n-1]);
		if (ans == loo)
			cout << -1 << endl;
		else
		{
			stack <int> st;
			Node* node = nodes[n - 1];
			do
			{
				st.push(node->id);
				node = node->from;
			} while (node != NULL);
			while(!st.empty())
			{
				cout << st.top() << " ";
				st.pop();
			}


		}
	

}