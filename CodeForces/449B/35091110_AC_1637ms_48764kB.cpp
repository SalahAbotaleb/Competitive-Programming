#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
//#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int OO = 0x3f3f3f3f;
const ll lOO = 0x3f3f3f3f3f3f3f3f;
struct Node
{
	int id = -1;
	ll cost = lOO;
	vector<pair<pair<int, Node*>, int>> neighbours;
	Node(int _id):id(_id){}
};

void dijkstra(Node* src)
{
	priority_queue <pair<ll, Node*>, vector<pair<ll, Node*>>, greater<pair<ll, Node*>>> q;
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
			ll weight = e.first.first;
			Node* to = e.first.second;
			int tnum = e.second;
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
	int n, m, k;
	cin >> n >> m >> k;
	vector <Node*> nodes(n);
	for (int i = 0; i < n;i++) nodes[i] = new Node(i);
	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;
		nodes[u]->neighbours.push_back({ { c,nodes[v] },0 });
		nodes[v]->neighbours.push_back({ { c,nodes[u] },0 });
	}
	for (int i = 0; i < k; i++)
	{
		int u, v, c;
		cin  >> v >> c;
		v--;
		u = 0;
		nodes[u]->neighbours.push_back({ { c,nodes[v] },1 });
		nodes[v]->neighbours.push_back({ { c,nodes[u] },1 });
	}
	dijkstra(nodes[0]);
	vector<bool> istrain(n, 0), ispath(n, 0);
	for (auto &node:nodes)
	{
		for (auto neighbour : node->neighbours)
		{
			int weight = neighbour.first.first;
			int train = neighbour.second;
			Node* n = neighbour.first.second;
			if (node->cost + weight == n->cost)
			{
				if (train) istrain[n->id] = 1;
				else
					ispath[n->id] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (istrain[i] && !ispath[i])
			ans++;
	}
	cout << k - ans << endl;
	return 0;
}