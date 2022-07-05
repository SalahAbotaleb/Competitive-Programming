#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
struct Node
{
	int id = -1;
	int dis = oo;
	//cost elevator#
	vector<pair<pair<int, int>, Node* >> neighbour;
};
int dijkstra(vector<pair<int,Node*>>& src,Node* target)
{
	priority_queue <pair<int, pair<int, Node*>>,vector<pair<int, pair<int, Node*>>>,greater<pair<int, pair<int, Node*>>>> q;
	for (auto& node : src)
	{
		q.push({ 0,{node.first,node.second} });
		node.second->dis = 0;
	}
		
	while (!q.empty())
	{
		int en = q.top().second.first;
		int weightSofar = q.top().first;
		Node* lvl = q.top().second.second;
		q.pop();
		if (weightSofar != lvl->dis)
			continue;
		if (lvl == target)
			break;
		for (auto &e : lvl->neighbour)
		{
			int nen = e.first.second;
			int weight = e.first.first;
			int new_weight = weight + weightSofar;
			Node* neighbour = e.second;
			
			if (new_weight < neighbour->dis)
			{
				neighbour->dis = new_weight;
				q.push({ new_weight,{nen,neighbour} });
			}
		}
	}
	return target->dis;
}
int main()
{
	int n, k;
	//ofstream out("ans.txt");
	while (cin >> n >> k)
	{
		vector<Node*> nodes(100);
		int times[100];
		memset(times, 0, 100 * sizeof(times[0]));
		for (int i = 0; i < 100; i++) nodes[i] = new Node, nodes[i]->id = i;

		for (int i = 0; i < n; i++) cin >> times[i];
		cin.ignore();
		vector<pair<int, Node*>> src;
		for (int i = 0; i < n; i++)
		{
			string s;
			getline(cin, s);
			stringstream ss(s);
			int tmp;
			vector<int> v;
			while (ss >> tmp)
			{
				v.push_back(tmp);
			}
			for (int j = 0; j < v.size(); j++)
			{

				for (int k = j + 1; k < v.size(); k++)
				{
					nodes[v[j]]->neighbour.push_back({ {(v[k] - v[j]) * times[i]+(v[j]==0?0:60),i},nodes[v[k]]});
					nodes[v[k]]->neighbour.push_back({ {(v[k] - v[j]) * times[i]+60,i},nodes[v[j]] });
				}
			}
			if (v[0] == 0)
				src.push_back({ 0,nodes[0] });
		}
		int ans = dijkstra(src, nodes[k]);
		if (ans == oo)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << ans << endl;

	}
}