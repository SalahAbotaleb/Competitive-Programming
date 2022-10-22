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
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
struct node
{
	int idx = -1;
	bool vis = 0;
	ll dis = loo;
	vector<node*>negihbour;
};
bool isvalid(int x, int y)
{
	return x<8 && x>-1 && y<8 && y>-1;
}

pair<int, int> bfs( queue<pair<int, int>>& q, int n, int m, int dis[2001][2001])
{
	int lx;
	int ly;
	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();
		int cx = curr.first;
		int cy = curr.second;
		lx = cx;
		ly = cy;
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx > -1 && ny > -1 && nx < n && ny < m && dis[cx][cy]+1<dis[nx][ny])
			{
				dis[nx][ny] = dis[cx][cy] + 1;
				q.push({ nx,ny });
			}
		}

	}
	return { lx,ly };
}
int mat[2001][2001];
int main()
{
	ofstream out("output.txt", ios::out);
	ifstream in("input.txt", ios::in);
	int n, m,k;
	in >> n >> m >>k;
	for (int i = 0; i < 2001; i++)
		for (int j = 0; j < 2001; j++)
			mat[i][j] = oo;

	queue<pair<int, int>>q;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		in >> x >> y;
		x--, y--;
		mat[x][y] = 0;
		q.push({ x,y });
	}
	auto p = bfs(q, n, m, mat);
	out << p.first + 1 << " " << p.second + 1 << endl;
	return 0;
}