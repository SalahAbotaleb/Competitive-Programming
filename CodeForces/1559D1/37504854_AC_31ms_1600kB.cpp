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
#define ll long long
using namespace std;
const int N = 1e5 + 5;
void intial(int* par, int* sz)
{
	for (int i = 0; i <= N; i++)
		par[i] = i, sz[i] = 1;
}
int findpar(int* par, int u)
{
	if (par[u] == u)
		return u;
	return par[u] = findpar(par, par[u]);
}
void connect(int u, int v, int* par, int* sz)
{
	u = findpar(par, u);
	v = findpar(par, v);
	if (u == v)
		return;
	if (sz[u] > sz[v])
		par[v] = u, sz[u] += sz[v];
	else
		par[u] = v, sz[v] += sz[u];
}
bool iscon(int u, int v, int* par)
{
	return (findpar(par, u) == findpar(par, v));
}
int MST(int* par, int* sz, vector<pair<int, pair<int, int>>>& lst)
{
	sort(lst.begin(), lst.end());
	int cost = 0;
	for (int i = 0; i < lst.size(); i++)
	{
		int u = lst[i].second.first;
		int v = lst[i].second.second;
		int c = lst[i].first;
		if (!iscon(u, v, par))
		{
			cost += c;
			connect(u, v, par, sz);
		}
	}
	return cost;
}
int main()
{
	int* par1 = new int[N];
	int* sz1 = new int[N];
	int* par2 = new int[N];
	int* sz2 = new int[N];
	intial(par1, sz1);
	intial(par2, sz2);
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	for (int i = 0; i < m1; i++)
	{
		int u, v;
		cin >> u >> v;
		connect(u, v,par1,sz1);
	}
	for (int i = 0; i < m2; i++)
	{
		int u, v;
		cin >> u >> v;
		connect(u, v, par2, sz2);
	}
	vector<pair<int, int>>ans;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if (!iscon(i, j, par1) && !iscon(i, j, par2))
			{
				ans.push_back({ i,j });
				connect(i, j, par1, sz1);
				connect(i, j, par2, sz2);
			}
	cout << ans.size() << endl;
	for (auto it : ans) cout << it.first << " " << it.second << endl;
	return 0;
}
