#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int dx [] = {1, 1,1,-1,-1,-1,0,0};
int dy [] = {1,-1,0,1,-1,0,1,-1};

struct Node
{
	bool vis = 0;
	bool alowed = 0;
	int dis = 0;
	
};

bool valid(int x, int y,map<pair<int,int>,Node>& mp)
{
	return x >= 0 && mp.find({x,y})!=mp.end();
}
int bfs(int sx,int sy,int tx,int ty, map<pair<int, int>, Node>& mp)
{
	queue <pair<int,int>> q;
	mp[{sx, sy}].dis = 0;
	q.push({sx,sy});
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		if (cx == tx && cy == ty)
			{
			return mp[{cx,cy}].dis;
			}
		for (int i = 0; i < 8; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (!valid(nx, ny,mp))
				continue;
			if (mp[{nx,ny}].vis==0)
			{
				mp[{nx, ny}].vis = 1;
				mp[{nx,ny}].dis = mp[{cx,cy}].dis + 1;
				q.push({nx,ny});
			}
		}
	}
	return -1;
}
int main()
{
	int ci, ct;
	int ri, rt;
	cin >> ri >> ci >> rt >> ct;
	int tc;
	cin >> tc;
	map<pair<int, int>, Node> mp;
	while (tc--)
	{
		int r, a, b;
		cin >> r >> a >> b;
		for (int i = a; i <= b; i++)
			mp[{r, i}].alowed = 1;
	}
	cout << bfs(ri, ci, rt, ct, mp) << endl;
	return 0;
}