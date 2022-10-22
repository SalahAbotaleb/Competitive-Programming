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
	int prev = -1;
	bool vis = 0;
	int deg = 0;
	vector<node*>neighbour;
};
void dfs(node* curr)
{
	curr->vis = 1;
	for (auto &it : curr->neighbour)
	{
		if (it->vis == 0)
		{
			it->prev=curr->id,dfs(it);
		}
	}
}
int main()
{
	//ofstream fout("test.txt");
	int n, r1,r2;
	cin >> n >> r1 >> r2;
	vector<node*>adj(n);
	for (int i = 0; i < n; i++)
	{
		adj[i] = new node;
		adj[i]->id = i + 1;
	}
	int ii = 0;
	for (int i = 0; i < n; i++)
	{
		int v, u;
		if (i+1 == r1)
			continue;
		cin >> v;
		u = i;
		v--;
		adj[u]->neighbour.push_back(adj[v]);
		adj[v]->neighbour.push_back(adj[u]);
	}
	dfs(adj[r2 - 1]);
	for (int i = 0; i < n; i++)
	{
		if (adj[i]->prev != -1)
			cout << adj[i]->prev << " ";
	}
	return 0;
}