#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <fstream>
#include <cassert>
#include <iomanip> 
#define ll long long
using namespace std;
const ll N = 1e9;
const int loo = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
struct node
{
	int idx;
	node* from = nullptr;
	ll dis = loo;
	int cst = 0;
	vector<pair<int, node*> > neighbour;
	/*node(int id)
	{
		idx = id;
	}*/
};
void dijkstra(node* src)
{
	priority_queue<pair<int, node*>, vector<pair<int, node*>>, greater<pair<int, node*>>>pq;
	src->dis = src->cst;
	pq.push({ src->cst,src });
	while (!pq.empty())
	{
		auto curr = pq.top().second;
		ll weight = pq.top().first;
		pq.pop();
		if (weight != curr->dis)
			continue;
		for (auto nxt : curr->neighbour)
		{
			ll nweight = weight + nxt.first * 2 + nxt.second->cst;
			node* neigh = nxt.second;
			if (nweight < neigh->dis)
			{
				neigh->dis = nweight;
				neigh->from = curr;
				pq.push({ nweight,neigh });
			}
		}
	}
}
void rst(vector<node*>& v)
{
	for (auto& it : v) it->dis = loo,it->from=nullptr;
}
int main()
{
	int tc;
	int cnt = 0;
	cin >> tc;
	int ref = tc;
	while (tc--)
	{
		int n, m, q;
		cin >> n;
		vector<node*>adj(n);
		unordered_map<int, string>mp;
		unordered_map<string, int>mp2;
		for (int i = 0; i < n; i++)
		{
			int c;
			string s;
			cin >> s >> c;
			adj[i] = new node;
			adj[i]->cst = c;
			mp[i] = s;
			mp2[s] = i;
			adj[i]->idx = i;
		}
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			string u, v;
			int c;
			cin >> u >> v >> c;
			int from = mp2[v];
			adj[mp2[u]]->neighbour.push_back({ c,adj[mp2[v]] });
			adj[mp2[v]]->neighbour.push_back({ c,adj[mp2[u]] });
		}
		cin >> q;
		cout << "Map #" << ++cnt << endl;
		for (int i = 1; i <= q; i++)
		{
			rst(adj);
			string u, v;
			int c;
			cout << "Query #" << i << endl;
			cin >> u >> v >> c;
			dijkstra(adj[mp2[u]]);
			stack<node*>s;
			s.push(adj[mp2[v]]);
			while (s.top()->from)
			{
				s.push(s.top()->from);
			}
			while (!s.empty())
			{
				cout << mp[s.top()->idx] << " \n"[s.size() == 1];
				s.pop();
			}
			cout <<"Each passenger has to pay : " << fixed << setprecision(2) << (adj[mp2[v]]->dis) * 1.1 / (double)c << " taka" << endl;
		}
		if (cnt != ref)
			cout << "\n";
	}


	return 0;
}