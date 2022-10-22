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
int dx[] = { 1,-1,0,0,1,1,-1,-1 };
int dy[] = { 0,0,1,-1,1,-1,1,-1 };
void bfs(int xi, int yi, int xf, int yf, map<pair<int, int>, int>& mp)
{
	mp[{xi, yi}] = 0;
	queue<pair<int, int>>q;
	q.push({ xi,yi });
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		if (cx == xf && cy == yf)
			break;
		for (int i = 0; i < 8; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx > -1 && nx <= 1e9 && ny > -1 && ny <= 1e9 && mp.find({ nx,ny }) != mp.end() && mp[{cx,cy}]+1<mp[{nx,ny}])
			{
				mp[{nx, ny}] = mp[{cx, cy}] + 1;
				q.push({ nx,ny });
			}

		}
	}
}
int main()
{
	int n;
	map <pair<int, int>, int>mp;
	int x0, y0, x1, y1;
	cin >> x0 >> y0 >> x1 >> y1;
	cin >> n;
	mp[{x0, y0}] = mp[{x1, y1}] = oo;
	for (int i = 0; i < n; i++)
	{
		int r, a, b;
		cin >> r >> a >> b;
		for (int j = a; j <= b; j++)
			mp[{r, j}] = oo;
	}
	bfs(x0, y0, x1, y1, mp);
	if (mp[{x1, y1}] != oo)
		cout << mp[{x1, y1}] << endl;
	else
		cout << -1 << endl;
	return 0;
}