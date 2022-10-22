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
int dx[] = { 1,-1,0,0};
int dy[] = { 0,0,1,-1};
char mat[101][101];
int dist[101][101][2];
// 0 closed  1 open
int bfs(int idxi, int idxj, int n ,int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dist[i][j][0] = dist[i][j][1] = 1e6;
	queue<pair<pair<int,int>,int>>q;
	dist[idxi][idxj][0] = 0;
	q.push({{ idxi,idxj },0});
	int cnt = -1;
	while (!q.empty())
	{
		int ci = q.front().first.first;
		int cj = q.front().first.second;
		int stat = q.front().second;
		if (ci == n - 1 || cj == m - 1 || ci == 0 || cj==0)
		{
			cnt = dist[ci][cj][stat] + 1;
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ni = ci + dx[i];
			int nj = cj + dy[i];
			if (ni<n && ni>-1 && nj<m && nj>-1 && dist[ci][cj][stat]+1<dist[ni][nj][stat])
			{
				if (mat[ni][nj] == '.' || (mat[ni][nj] == 'D' && stat == 1) || mat[ni][nj] == 'O' || mat[ni][nj]=='H' || mat[ni][nj]=='C')
				{
					int nstat = (mat[ni][nj] == 'O' ? 1 : (mat[ni][nj] == 'C' ? 0 : stat));
					dist[ni][nj][nstat] = dist[ci][cj][stat] + 1;
					q.push({ {ni,nj },nstat});
				}
			}
		}
	}
	return cnt;
}
int main()
{
	int n, m;
	while (cin >> n >> m && (n!=-1&&m!=-1))
	{
		int bi, bj;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> mat[i][j];
				if (mat[i][j] == 'H')
					bi = i, bj = j;
			}
		cout << bfs(bi, bj, n, m) << endl;
	}
	return 0;
}