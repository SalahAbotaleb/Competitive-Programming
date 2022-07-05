#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;
const int OO = 0x3f3f3f3f;
struct Cost
{
	int weight = -1;
};
struct Node
{
	int cost = OO;
	vector<pair<int,Node*>> neighbours;
};

void dijkstra(Node* src)
{
	priority_queue <pair<int, Node*>,vector<pair<int,Node*>>,greater<pair<int, Node*>>> q;
	src->cost = 0;
	q.push({ 0,src });
	while (!q.empty())
	{
		Node* node = q.top().second;
		int weightSofar = q.top().first;
		q.pop();
		if (weightSofar != node->cost)
			continue;
		for (auto e : node->neighbours)
		{
			int weight = e.first;
			Node* to = e.second;
			if (weight + node->cost  < to->cost)
			{
				to->cost = weight + node->cost ;
				q.push({ to->cost,to });
			}
		}
	}
}
int main()
{
	int n, m,k;
	cin >> n >> m >> k;
	vector <Node*> nodes(n);
	vector<vector<int>>grid(n, vector<int>(n));
	vector<pair<int, int>> e;
	for (auto& node : nodes) node = new Node;
	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;
		nodes[u]->neighbours.push_back({ c,nodes[v]});
		nodes[v]->neighbours.push_back({ c,nodes[u]});
		e.push_back({ u,v });
	}
	vector <pair<int, int>> vec;
	for (int i = 0; i < k; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		vec.push_back({ u,v });
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			nodes[j]->cost = OO;
		}
		dijkstra(nodes[i]);
		for (int j = 0; j < n; j++)
			grid[i][j] = nodes[j]->cost;
	}
	int Mans = OO;
	for (int i = 0; i < m; i++)
	{
		int u = e[i].first;
		int v = e[i].second;
		int ans=0;
		for (int j = 0; j < k; j++)
		{
			int st = vec[j].first;
			int en = vec[j].second;
			int fir = grid[st][en];
			int sec = grid[st][u] + grid[v][en];
			int thir = grid[st][v] + grid[u][en];
			ans += min({fir,sec,thir});
		}
		Mans = min(Mans, ans);
	}
	cout << Mans << endl;
	return 0;
}