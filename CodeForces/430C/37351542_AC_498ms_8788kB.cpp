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
	int ic = -1;
	int fc = -1;
	vector<node*>neighbour;
};
void dfs(node* curr, vector<int> arr, int roun, vector<int>& v)
{
	curr->vis = 1;
	if (arr[roun])
	{
		if (curr->ic == curr->fc)
		{
			arr[roun] = 0;
			v.push_back(curr->id);
		}
	}
	else
	{
		if (curr->ic != curr->fc)
		{
			arr[roun] = 1;
			v.push_back(curr->id);
		}
	}
	for (auto it : curr->neighbour)
	{
		if (it->vis == 0)
		{
			dfs(it, arr, 1 - roun, v);
		}
	}
}
int main()
{
	//ofstream fout("test.txt");
	int n, m;
	cin >> n;
	vector<node*>adj(n);
	for (int i = 0; i < n; i++)
	{
		adj[i] = new node;
		adj[i]->id = i + 1;
	}
	for (int i = 0; i < n - 1; i++)
	{
		int v, u;
		cin >> u >> v;
		u--, v--;
		adj[u]->neighbour.push_back(adj[v]);
		adj[v]->neighbour.push_back(adj[u]);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> adj[i]->ic;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> adj[i]->fc;
	}
	vector<int>v;
	vector<int> arr = { 0,0 };
	dfs(adj[0], arr, 1, v);
	cout << v.size() << endl;
	for (auto x : v) cout << x << endl;
	return 0;
}