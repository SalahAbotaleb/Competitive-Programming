#include <iostream>
#include <queue>
using namespace std;
const int N = 100;
int n, m;
char mat[N][N];
int vis[N][N][2]; // 0 for closed , 1 for open
int srcx, srcy;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1,1 };
struct Point
{
	int x;
	int y;
	int curr;
	Point(int _x,int _y,int _curr):x(_x),y(_y),curr(_curr){}
};
bool valid(int r, int c)
{
	return r >= 0 && r < n&& c >= 0 && c < m && mat[r][c]!='W';
}
int bfs()
{
	queue<Point>q;
	q.push(Point(srcx, srcy, 0));
	vis[srcx][srcy][0] = 1;
	while (!q.empty())
	{
		int cx = q.front().x;
		int cy = q.front().y;
		int cstate = q.front().curr;
		q.pop();
		if (cx == 0 || cx == n - 1 || cy == 0 || cy == m - 1)
		{
			return vis[cx][cy][cstate];
		}
		for (int i = 0; i < 4; i++)
		{
			int nr = cx + dx[i];
			int nc = cy + dy[i];
			if (!valid(nr, nc))
				continue;
			int nstate = cstate;
			if (mat[nr][nc] == 'C')
				nstate = 0;
			if (mat[nr][nc] == 'O')
				nstate = 1;
			if (vis[nr][nc][nstate])
				continue;
			if (mat[nr][nc] == 'D' && nstate == 0)
				continue;
			vis[nr][nc][nstate] = vis[cx][cy][cstate] + 1;
			q.push(Point(nr, nc, nstate));
		}
	}
	return -1;
}
int main()
{
	while (cin >> n >> m, n != -1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> mat[i][j];
				if (mat[i][j] == 'H')
					srcx = i, srcy = j;
			}
		}
		cout << bfs() << endl;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				vis[i][j][1] = vis[i][j][0] = 0;
	}

}