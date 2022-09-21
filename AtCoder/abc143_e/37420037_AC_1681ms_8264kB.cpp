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
#define F first
#define S second
using namespace std;
const int N = 1e6 + 5;
const ll loo = 0x3f3f3f3f3f3f3f3f;
/*int arr[N];
void primes()
{
	arr[0] = arr[1] = 1;
	for (int i = 2; i * i < N; i++)
	{
		if (arr[i] == 0)
		{
			for (int j = i + i; j < N; j += i)
			{
				arr[j] = 1;
			}
		}
	}
}
ll power(ll b, ll pow)
{
	ll ans = 1;
	while (pow != 0)
	{
		if (pow & 1)
			ans *= b;
		b *= b;
		pow >>= 1;
	}
	return ans;
}*/

void init() {
	cin.tie(0);
	cin.sync_with_stdio(0);
}
pair<ll, ll> dist[301][301]; //[from][to] f:cnt s:curr_fuel
vector<pair<ll, int>>adj[301];
void dijkstra(ll l, int idx)
{
	priority_queue <pair<pair<ll, ll>, int>> pq;
	dist[idx][idx] = { 0,l };
	pq.push({ {0,l},idx });
	while (!pq.empty())
	{
		int cnt =-pq.top().F.F;
		int curr_fuel = pq.top().F.S;
		int curr = pq.top().S;
		pq.pop();
		if (cnt > dist[idx][curr].F || (dist[idx][curr].F == cnt && curr_fuel < dist[idx][curr].S))
			continue;
		for (auto it : adj[curr])
		{
			ll length = it.first;
			int n_idx = it.second;
			ll new_cnt = cnt + (curr_fuel < length ? 1 : 0);
			ll new_fuel = (curr_fuel < length ? l - length : curr_fuel - length);
			if (new_cnt < dist[idx][n_idx].first || (new_cnt == dist[idx][n_idx].first && new_fuel > dist[idx][n_idx].second))
			{
				dist[idx][n_idx].first = new_cnt;
				dist[idx][n_idx].second = new_fuel;
				pq.push({ {-new_cnt,new_fuel},n_idx });
			}

		}
	}
}
int main()
{
	for (int i = 0; i < 301; i++)
		for (int j = 0; j < 301; j++)
			dist[i][j] = { loo,0 };
	init();
	int n, m, l, q;
	cin >> n >> m >> l;
	for (int i = 0; i < m; i++)
	{

		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;
		if (c > l)
			continue;
		adj[u].push_back({ c,v });
		adj[v].push_back({ c,u });
	}
	cin >> q;
	//ofstream out("test.txt");
	for (int i = 0; i < n; i++)
	{
		dijkstra(l, i);
	}
	for (int i = 0; i < q; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		if (dist[u][v].F != loo)
			cout << dist[u][v].F << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}