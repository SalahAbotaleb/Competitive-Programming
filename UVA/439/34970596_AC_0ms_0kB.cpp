#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 8;
int dis[N][N];
int dx[] = {2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,1,-1,2,2,-2,-2};
struct Point
{
	int x;
	int y;
	Point(int _x,int _y):x(_x),y(_y){}
};
bool valid(int x, int y)
{
	return x >= 0 && x < 8 && y>=0 && y < 8;
}
int bfs(int sx,int sy,int tx,int ty)
{
	queue <Point> q;
	dis[sx][sy] = 1;
	q.push(Point(sx, sy));
	while (!q.empty())
	{
		Point node = q.front();
		q.pop();
		if (node.x == tx && node.y == ty)
			{
			return dis[tx][ty];
			}
		for (int i = 0; i < 8; i++)
		{
			int nx = node.x + dx[i];
			int ny = node.y + dy[i];
			if (!valid(nx, ny))
				continue;
			if (!dis[nx][ny])
			{
				
				dis[nx][ny] = dis[node.x][node.y] + 1;
				q.push(Point(nx, ny));
			}
		}
	}
}
int main()
{
	char ci, ct;
	int ri, rt;
	while (cin >> ci >> ri >> ct >> rt)
	{
		int res = bfs(ri - 1, ci - 'a', rt - 1, ct - 'a') - 1;
		printf("To get from %c%d to %c%d takes %d knight moves.\n",ci,ri,ct,rt,res);
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				dis[i][j] = 0;
	}
//s
	return 0;
}