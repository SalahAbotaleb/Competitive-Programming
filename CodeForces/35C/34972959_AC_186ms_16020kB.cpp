#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;
const int N = 2000;
int dis[N][N];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
struct point
{
	int x;
	int y;
	point(int _x,int _y):x(_x),y(_y){}
};
point bfs(int n,int m,queue <point>& q)
{
	point p(0,0);
	while (!q.empty())
	{
		p = q.front();
		int cx =q.front().x;
		int cy = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (!(nx >= 0 && nx < n && ny >= 0 && ny < m))
				continue;
			if (dis[nx][ny])
				continue;
			dis[nx][ny] = dis[cx][cy] + 1;
			q.push(point(nx, ny));

		}

	}
	return p;
}
int main()
{
	ofstream out("output.txt",ios::out);
	ifstream in("input.txt",ios::in);
	int n,m,k;
	in >> n >> m >> k;
	queue <point> q;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		in >> x >> y;
		x--, y--;
		dis[x][y] = 1;
		q.push(point(x, y));
	}
	point p = bfs(n, m, q);
	out << p.x+1<<" "<<p.y+1 << endl;
	return 0;
}