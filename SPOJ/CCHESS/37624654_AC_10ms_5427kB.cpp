#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <fstream>
#include <cassert>
#include <iomanip> 
#define ll long long
using namespace std;
const ll N = 1e9;
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
int dx[] = { 1,-1,2,-2,1,-1,2,-2 };
int dy[] = { 2,2,1,1,-2,-2,-1,-1 };
struct node
{
	int idx;
	node* from = nullptr;
	ll dis = loo;
	vector<pair<int, node*> > neighbour;
	node(int id)
	{
		idx = id;
	}
};
ll dist[8][8];
ll dijkstra(int sx, int sy, int ex, int ey)
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			dist[i][j] = loo;
	priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>>pq;
	dist[sx][sy] = 0;
	pq.push({ 0,{sx,sy} });
	while (!pq.empty())
	{
		int cx = pq.top().second.first;
		int cy = pq.top().second.second;
		ll weight = pq.top().first;
		pq.pop();
		if (weight != dist[cx][cy])
			continue;
		if (cx == ex && cy == ey)
			break;
		for (int i = 0; i < 8; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (!(nx > -1 && nx<8 && ny>-1 && ny < 8))
				continue;
			ll cost = weight + cx * nx + cy * ny;
			if (cost < dist[nx][ny])
			{
				dist[nx][ny] = cost;
				pq.push({ cost,{nx,ny} });
			}

		}
	}
	return dist[ex][ey];
}
void rst(vector<node*>& v)
{
	for (auto& it : v) it->dis = loo;
}
int main()
{

	int sx, sy, ex, ey;
	while (cin>>sx >> sy >> ex >> ey)
	{
		ll ans = dijkstra(sx, sy, ex, ey);
		cout <<(ans!=loo?ans:-1) << endl;
	}

	return 0;
}