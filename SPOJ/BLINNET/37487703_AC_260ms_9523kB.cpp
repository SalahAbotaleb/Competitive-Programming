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
	int* par = new int[N];
	int* sz = new int[N];
	int tc;
	cin >> tc;
	while (tc--)
	{
		intial(par, sz);
		int n;
		cin >> n;
		//unordered_map<string, int>mp;
		vector<pair<int, pair<int, int>>> lst;
		for (int i = 1; i <= n; i++)
		{
			string nm;
			cin >> nm;
			int m;
			cin >> m;
			//mp[nm] = i;
			while (m--)
			{
				int u, v, c;
				cin >> v >> c;
				u = i;
				lst.push_back({ c,{u,v} });
			}
		}
		cout << MST(par, sz, lst) << endl;
	}
	return 0;
}
