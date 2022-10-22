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
int main()
{
	int* par = new int[N];
	int* sz = new int[N];
	int n, m;
	cin >> n >> m;
	intial(par, sz);
	set<int>s;
	set<int>s1;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int tc;
		cin >> tc;
		cnt += (tc == 0);
		int beg = -1;
		while (tc--)
		{
		int u;
		cin >> u;
		if (beg == -1)
			beg = u;
		s1.insert(u);
		connect(u, beg, par, sz);
		}
	}
	 for (int i = 1; i <= m; i++)
		 if(s1.find(i)!=s1.end())
		 s.insert(findpar(par,i));
	 cout << cnt + (s.size()?s.size()- 1:0) << endl;
	return 0;
}
