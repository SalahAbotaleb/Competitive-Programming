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
#define ll long long
using namespace std;
const int N = 1e5;
struct node
{
	int id = -1;
	bool vis = 0;
	vector<node*>neighbour;
};
int dfs(node* curr)
{
	curr->vis = 1;
	int mx=0;
	for (auto it : curr->neighbour)
	{
		if (it->vis == 0)
			mx+= 1+dfs(it);
	}
	return mx;
}
int main()
{
	int n, m;
	//ofstream fout("test.txt");
	while (cin >> n >> m && n+m)
	{
		vector<node*>adj(n);
		for (auto& it : adj) it = new node;
		map<string, int>mp;
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			mp[s] = i;
		}
		for (int i = 0; i < m; i++)
		{
			string u, v;
			cin >> u >> v;
			adj[mp[u]]->neighbour.push_back(adj[mp[v]]);
			adj[mp[v]]->neighbour.push_back(adj[mp[u]]);
		}
		int mx = 0;
		for (auto it : adj)
		{
			if(!it->vis)
			mx = max(mx, dfs(it));
		}
		cout << mx+1 << endl;
	}
	return 0;
}