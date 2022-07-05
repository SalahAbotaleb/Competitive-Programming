#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iomanip>
#include <fstream>
#define ll long long
using namespace std;
const ll lOO = 0x3f3f3f3f3f3f3f3f;
struct Node
{
	string name;
	ll cost = lOO;
	ll fees = -1;
	Node* from=NULL;
	vector <pair<ll, Node*>> neighbours;
};
ll dijkstra(Node* src,Node* target)
{
	priority_queue <pair<ll, Node*>,vector<pair<ll,Node*>>,greater<pair<ll, Node*>>> q;
	src->cost = src->fees;
	q.push({ src->fees,src });
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
			if (weight + node->cost + to->fees < to->cost)
			{
				to->cost = weight + node->cost + to->fees;
				q.push({ to->cost,to });
				to->from = node;
			}
		}
	}
	return target->cost;
}
int main()
{
	//ofstream out("res.txt");
	int tc;
	cin >> tc;
	for (int j = 0; j < tc; j++)
	{
		int n, m ;
		cin >> n ;
		unordered_map <string, int> mp;
		vector <Node*> nodes(n);
		for (auto& node : nodes) node = new Node;
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			nodes[i]->name = s;
			mp[s] = i;
			cin>>nodes[i]->fees;
			
		}
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			string u, v;
			int c;
			cin >> u >> v >> c;
			nodes[mp[u]]->neighbours.push_back({ 2*c,nodes[mp[v]] });
			nodes[mp[v]]->neighbours.push_back({ 2*c,nodes[mp[u]] });
		}
		int q;
		cin >> q;
		cout << "Map #" << j + 1 << "\n";
		for (int i = 0; i < q; i++)
		{
			for (auto& node : nodes) node->cost = lOO, node->from = NULL;
			string u, v;
			int cnt;
			cin >> u >> v >> cnt;
			ll ans = dijkstra(nodes[mp[u]], nodes[mp[v]]);
			Node* ptr = nodes[mp[v]];
			cout << "Query #" << i + 1 << "\n";
			vector<string> s;
			do
			{
				s.push_back(ptr->name);
				ptr = ptr->from;
			} while (ptr!=NULL);
			for (int i = s.size() - 1; i >= 0; i--)
				cout << s[i] << " \n"[i == 0];
			cout << "Each passenger has to pay : " <<fixed<< setprecision(2) << ((double)ans * 1.1) / cnt << " taka" << endl;
		}
		if(j!=tc-1)
			cout << endl;
	}
}