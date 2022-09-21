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
struct rec
{
	int a;
	int b;
	rec(int i, int j)
	{
		a = i;
		b = j;
	}
};
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		int l1 = n;
		int l2 = n - 1;
		cout << 2 << endl;
		for (int i = 0; i < n - 1; i++)
		{
			cout << l1 << " " << l2 << endl;
			l1 = (l1 + l2 + 2 - 1) / 2;
			l2 = l2 - 1;
		}
		
	
	}
	return 0;
}