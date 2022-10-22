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
	ll dis = loo;
	vector<node*>negihbour;
};
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int dis[500][500];
char sym[500][500];
void bfs(int x, int y, int sz, int free, int n, int m)
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
}
int main()
{
	int n, m, k, x, y, sz;
	sz = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> sym[i][j];
			if (sym[i][j] == '.')
				sz++, x = i, y = j;
		}
	bfs(x, y, sz, k, n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (dis[i][j] == 1 || (sym[i][j]=='.'&&dis[i][j]==0))
				cout << 'X';
			else
				cout << sym[i][j] ;
		cout << endl;
	}


	return 0;
}