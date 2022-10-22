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
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
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
ll dist[1000][1000];
ll cst[1000][1000];
ll dijkstra(int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dist[i][j] = loo;
	priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>>pq;
	dist[0][0] = cst[0][0];
	pq.push({ dist[0][0],{0,0}});
	while (!pq.empty())
	{
		int cx = pq.top().second.first;
		int cy = pq.top().second.second;
		ll weight = pq.top().first;
		pq.pop();
		if (weight != dist[cx][cy])
			continue;
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (!(nx > -1 && nx<n && ny>-1 && ny < m))
				continue;
			ll cost = weight + cst[nx][ny];
			if (cost < dist[nx][ny])
			{
				dist[nx][ny] = cost;
				pq.push({ cost,{nx,ny} });
			}

		}
	}
	return dist[n-1][m-1];
}
void rst(vector<node*>& v)
{
	for (auto& it : v) it->dis = loo;
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> cst[i][j];
		cout << dijkstra(n, m) << endl;
	}
	return 0;
}