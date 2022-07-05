#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
	int dis = 0;
	int type = 0;
	int val = 0;
};
struct Point
{
	int x;
	int y;
	Point(int _x,int _y):x(_x),y(_y){}
};
bool valid(int r,int c,int n,int m, vector<vector<Node> >& grid)
{
	return r >= 0 && r < n&& c >= 0 && c < m&& grid[r][c].type == 1;
}
bool bfs(int x,int y,int target,int n,int m, vector<vector<Node> >&grid,vector<Point>&v)
{
	queue<Point>q;
	int dr[] = { 0,0,-1,1 };
	int dc[]={1,-1,0,0};
	q.push(Point(x,y));
	v.push_back(Point(x, y));
	grid[x][y].dis = 1;
	while (!q.empty())
	{
		int r = q.front().x;
		int c = q.front().y;
		q.pop();
		
		for (int i=0;i<4;i++)
		{
			int nr = r +dr[i];
			int nc = c + dc[i];
			if (valid(nr,nc,n,m,grid)&&grid[nr][nc].dis==0)
			{
				grid[nr][nc].dis =  1;
				q.push(Point(nr, nc));
				v.push_back(Point(nr, nc));
			}

		}
	}
	return (v.size()>=target);
}
void print(vector<vector<Node> >& grid, vector<Point>& v,int target)
{
	for (int i=0;i<target;i++)
	{
		grid[v[i].x][v[i].y].type = 2;
	}
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			if (grid[i][j].type == 0)
				cout << '#';
			else
				if (grid[i][j].type == 1)
					cout << 'X';
				else
					cout << '.';
		}
		cout << endl;
	}
}
int main()
{
	int n,m,target;
	int dots = 0;
	cin >> n>>m>>target;
	vector<vector<Node> >grid(n, vector <Node>(m));
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c == '#')
				grid[i][j].type = 0;
			else
				grid[i][j].type = 1, dots++;
		}
	int tdots = dots - target;
	for (int i = 0; i < n; i++)
	{
		bool out = 0;
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j].dis == 0 && grid[i][j].type == 1)
			{
				vector <Point> v;
				if (bfs(i, j, tdots, n, m, grid, v))
				{
					print(grid, v,tdots);
					//cout << "*-----*" << endl;
					out = 1;
					break;
				}
			}
		}
		if (out)
			break;
	}
	return 0;
}