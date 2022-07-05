#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
int dr[] = {2,2,-2,-2,1,-1,1,-1};
int dc[] = {1,-1,1,-1,2,2,-2,-2};
const int OO = 0x3f3f3f3f;
struct Node
{
	int cost = OO;
};
struct Point
{
	int r = -1;
	int c = -1;
	Point(int _r,int _c):r(_r),c(_c){}
};
bool valid(int r, int c)
{
	return r > -1 && r<8 && c>-1 && c < 8;
}
int dijkstra(int sr,int sc,int tr,int tc)
{
	priority_queue <pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
	vector <vector<Node>>grid(8, vector<Node>(8));
	grid[sr][sc].cost = 0;
	q.push({ 0,{sr,sc}});
	while (!q.empty())
	{
		int cr = q.top().second.first;
		int cc = q.top().second.second;
		int weightSofar = q.top().first;
		q.pop();
		if (cr == tr && cc == tc)
			break;
		if (weightSofar != grid[cr][cc].cost)
			continue;
		for (int i = 0; i < 8; i++)
		{
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if (!valid(nr, nc))
				continue;
			int weight = nr * cr + nc * cc;
			if (weight + weightSofar < grid[nr][nc].cost)
			{
				grid[nr][nc].cost = weight + weightSofar;
				q.push({grid[nr][nc].cost,{nr,nc}});
			}
		}
	}
	return grid[tr][tc].cost;
}
int main()
{


	int sr, sc, tr, tc;
	while (cin >> sr >> sc >> tr >> tc)
	{
		
		int ans = dijkstra(sr, sc, tr, tc);
		if (ans == OO)
			cout << -1 << endl;
		else
			cout << ans << endl;

	}

}