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
	Node(int _id) :id(_id) {}
};

bool dijkstra(vector<Node*>&nodes,int mxwisdom,int mxcost)
{
	Node* src = nodes.front();
	for (auto& node : nodes) node->cost = lOO;
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
			int wisdomlvl = e.second;
			if (wisdomlvl<=mxwisdom && weight + node->cost < to->cost)
			{
				to->cost = weight + node->cost;
				q.push({ to->cost,to });
			}
		}
	}
	return (nodes.back()->cost < mxcost);
}
int binarysearch(vector<Node*>& nodes, int mxcost)
{
	int s = 1, e = 1e9 + 1, md;
	while (e-s > 0)
	{
		md = (s + e) / 2;
		if (dijkstra(nodes, md, mxcost))
			e = md;
		else
			s = md + 1;
	}
	if (e > 1e9) return -1;
	return e;
}
int main()
{
	int n, m, k;
	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> n >> m >> k;
		vector <Node*> nodes(n);
		for (int i = 0; i < n; i++) nodes[i] = new Node(i);
		for (int i = 0; i < m; i++)
		{
			int u, v, c, wl;
			cin >> u >> v >> c >> wl;
			u--, v--;
			nodes[u]->neighbours.push_back({ { c,nodes[v] },wl });
			nodes[v]->neighbours.push_back({ { c,nodes[u] },wl });
		}
		cout << binarysearch(nodes, k) << endl;
	}
	return 0;
}