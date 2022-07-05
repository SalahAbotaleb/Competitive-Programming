#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int mat[25][25];
int vis[25][25];
int n, m;
int dx [] = {1, 1,1,-1,-1,-1,0,0};
int dy [] = {1,-1,0,1,-1,0,1,-1};
struct Point
{
	int x;
	int y;
	Point(int _x,int _y):x(_x),y(_y){}
};
bool valid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}
int bfs(int sx,int sy)
{
	queue<Point> q;
	q.push(Point(sx,sy));
	vis[sx][sy] = 1;
	int cnt = 0;
	while (!q.empty())
	{
		Point p(q.front().x, q.front().y);
		q.pop();
		cnt++;
		for (int i = 0; i < 8; i++)
		{
			int nx = p.x + dx[i];
			int ny = p.y + dy[i];
			if (!valid(nx, ny))
				continue;
			if (vis[nx][ny]!=0)
				continue;
			
			if (mat[nx][ny]==1)
			{
				vis[nx][ny] = 1;
				q.push(Point(nx, ny));
			}
		}
		
	}
	return cnt;
}
int main()
{
	int tc;
	cin >> tc;
	cin.ignore();
	cin.ignore();
	while (tc--)
	{
		vector<Point>p;
		vector<string>v;
		string s;
		while (getline(cin, s) && s != "")
		{
			v.push_back(s);
		}
		 n = v.size();
		 m = v[0].size();
		 for(int i=0;i<n;i++)
			for (int j = 0; j < m; j++)
			{
				mat[i][j] = v[i][j] - '0';
				if (mat[i][j] == 1)
					p.push_back(Point(i, j));
			}
		int mx = 0;
		for (auto& point : p)
		{
			if(!vis[point.x][point.y])
			mx = max(mx, bfs(point.x, point.y));
		}
		cout << mx << endl;
		if(tc)
		cout << endl;
		for (int i = 0; i < 25; i++)
			for (int j = 0; j < 25; j++)
				vis[i][j] = 0;
	}
	return 0;
}