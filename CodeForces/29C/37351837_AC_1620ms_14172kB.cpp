#include<iostream>
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
	int deg = 0;
	vector<node*>neighbour;
};
void dfs(node* curr, vector<int>& v)
{
	curr->vis = 1;
	for (auto it : curr->neighbour)
	{
		if (it->vis == 0)
		{
			dfs(it, v);
		}
	}
	v.push_back(curr->id);
}
int main()
{
	//ofstream fout("test.txt");
	int n, m;
	cin >> n;
	vector<node*>adj(n+5);
	for (int i = 0; i < n+5; i++)
	{
		adj[i] = new node;
	}
	map<int, int>mp;
	int ii = 0;
	for (int i = 0; i < n; i++)
	{
		int v, u;
		cin >> u >> v;
		if (mp.find(u) == mp.end())
		{
			mp[u] = ii;
			adj[mp[u]]->id = u;
			ii++;
		}
		if (mp.find(v) == mp.end())
		{
			mp[v] = ii;
			adj[mp[v]]->id = v;
			ii++;
		}
		adj[mp[u]]->neighbour.push_back(adj[mp[v]]);
		adj[mp[u]]->deg++, adj[mp[v]]->deg++;
		adj[mp[v]]->neighbour.push_back(adj[mp[u]]);
	}
	int idx = 0;
	for (int i = 0; i < n; i++)
	{
		if (adj[i]->deg == 1)
		{
			idx = i;
			break;
		}
	}
	vector<int>v;
	dfs(adj[idx], v);
	for (auto x : v) cout << x << endl;
	return 0;
}