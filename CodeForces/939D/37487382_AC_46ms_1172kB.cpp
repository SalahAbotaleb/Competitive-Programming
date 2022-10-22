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
int findpar(int* par,int u)
{
	if (par[u] == u)
		return u;
	return par[u] = findpar(par, par[u]);
}
void connect(int u,int v,int *par,int *sz)
{
	u = findpar(par,u);
	v = findpar(par,v);
	if (sz[u] > sz[v])
		par[v] = u, sz[u] += sz[v];
	else
		par[u] = v, sz[v] += sz[u];
}
bool iscon(int u, int v,int *par)
{
	return (findpar(par, u) == findpar(par, v));
}
int main()
{
	int *par=new int[N];
	int *sz=new int[N];
	int n;
	cin >> n ;
	string s1, s2;
	cin >> s1 >> s2;
	intial(par,sz);
	vector<pair<char, char>>ans;
	for (int i = 0; i < n; i++)
	{
		int u, v;
		u = s1[i] - 'a';
		v = s2[i] - 'a';
		if(!iscon(u,v,par))
		connect(u, v, par, sz),ans.push_back({u+'a',v+'a'});
	}
	cout << ans.size() << endl;
	for (auto it : ans) cout << it.first << " " << it.second << endl;
	return 0;
}
