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
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const ll loo = 0x3f3f3f3f3f3f3f3f;
struct node
{
	int idx = -1;
	bool vis = 0;
	int in = 0;
	vector<pair<node*, int>>negihbour;
};
struct record
{
	int f;
	int t;
	int d;
	bool operator < (record& r)
	{
		return f < r.f;
	}
};
int dfs(node* curr, int& mn)
{
	curr->vis = 1;
	int l = curr->idx;
	for (auto& it : curr->negihbour)
	{
		if (it.first->vis == 1)
			continue;
		mn = min(mn, it.second);
		l = dfs(it.first, mn);
	}
	return l;
}
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int dis[500][500];
char sym[500][500];
/*void bfs(int x, int y, int sz, int free, int n, int m)
{
	queue<pair<int, int>>q;
	q.push({ x,y });
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dis[i][j] = 0;
	for (int i = 0; i < sz - free; i++)
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		dis[cx][cy] = 2;
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx > -1 && nx<n && ny>-1 && ny < m && !dis[nx][ny] && sym[nx][ny] == '.')
			{
				dis[nx][ny]=1;
				q.push({ nx,ny });
			}
		}
	}
}*/
int main()
{
	int n, m;
	cin >> n >> m;
	vector<node*>adj(n);
	for (int i = 0; i < n; i++) adj[i] = new node, adj[i]->idx = i + 1;
	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;
		adj[u]->negihbour.push_back({ adj[v],c });
		adj[v]->in++;
	}
	vector<record>ans;
	for (int i = 0; i < n; i++)
	{
		if (adj[i]->vis == 0 && adj[i]->in == 0)
		{
			int mn = INT_MAX;
			int l = dfs(adj[i], mn);
			if (mn != INT_MAX)
			{
				record r;
				r.f = i + 1, r.t = l, r.d = mn;
				ans.push_back(r);
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (auto& it : ans) cout << it.f << " " << it.t << " " << it.d << endl;
	return 0;
}