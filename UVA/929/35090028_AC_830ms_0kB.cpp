#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
const int OO = 0x3f3f3f3f;
struct Node
{
	int dis = OO;
	int cost = 0;
};
bool valid(int r, int c, int n, int m)
{
	return r > -1 && r<n && c>-1 && c < m;
}
int dijkstra(vector<vector<Node>>& grid,int n,int m)
{
	int dr[] = {0,0,1,-1};
	int dc[] = {1,-1,0,0};
	priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> q;
	q.push({ grid[0][0].cost, { 0,0 } });
	grid[0][0].dis = grid[0][0].cost;
	while (!q.empty())
	{
		int weightSofar = q.top().first;
		int cr = q.top().second.first;
		int cc = q.top().second.second;
		q.pop();
		if (weightSofar != grid[cr][cc].dis)
			continue;
		if (cr == n - 1 && cc == m - 1)
			break;
		for (int i = 0; i < 4; i++)
		{
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if (!valid(nr, nc, n, m))
				continue;
			int weight = grid[nr][nc].cost;
			if (weight + weightSofar < grid[nr][nc].dis)
			{
				grid[nr][nc].dis = weight + weightSofar;
				q.push({ grid[nr][nc].dis,{nr,nc} });
			}
		}
	}
	return grid[n-1][m-1].dis;
}
int main()
{
	int tc;
	cin >> tc;
	int n, m;
	while (tc--)
	{
		cin >> n >> m;
		vector<vector<Node>>grid(n, vector<Node>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> grid[i][j].cost;
		int ans = dijkstra(grid, n, m);
		cout << ans << endl;
	}
	return 0;
}