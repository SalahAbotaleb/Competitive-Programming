#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#include <iomanip>
#include <stack>
#include <fstream>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int oo = 0x3f3f3f3f;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
struct node
{
	int idx = -1;
	bool vis = 0;
	ll dis = loo;
	vector<node*>negihbour;
};
bool isvalid(int x, int y)
{
	return x<8 && x>-1 && y<8 && y>-1;
}
void dfs(node* curr, node* par,int& count)
{
	curr->vis = 1;
	for (auto neigh : curr->negihbour)
	{
		if (neigh->vis == 0)
			dfs(neigh, curr, count);
		else
			if (neigh != par)
				count++;
	}
}

int mat[2001][2001];
int main()
{
	int n, m;
	cin >> n >> m;
	vector<node*>adj(n);
	for (int i = 0; i < n; i++)
	{
		adj[i] = new node;
	}
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u]->negihbour.push_back(adj[v]);
		adj[v]->negihbour.push_back(adj[u]);
	}
	int c = 0;
	dfs(adj[0], nullptr, c);
	c /= 2;
	if (c != 1)
	{
		return cout << "NO\n",0;
	}
	for(auto it:adj)
		if(it->vis==0)
			return cout << "NO\n", 0;
	cout << "FHTAGN!\n";
	return 0;
}