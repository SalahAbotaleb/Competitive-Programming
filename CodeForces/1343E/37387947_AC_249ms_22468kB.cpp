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
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const ll loo = 0x3f3f3f3f3f3f3f3f;
int arr[N];
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
}

void init() {
	cin.tie(0);
	cin.sync_with_stdio(0);
}
struct node
{
	int id = -1;
	ll dis[3] = {-1,-1,-1};
	node* from = nullptr;
	vector<node*>neighbour;
	node(int i)
	{
		id = i;
	}
};
void bfs(node* src, int idx)
{
	queue<node*>q;
	src->dis[idx] = 0;
	q.push(src);
	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();
		for (auto it : curr->neighbour)
		{
			if (it->dis[idx] == -1)
			{
				it->dis[idx] = curr->dis[idx] + 1;
				q.push(it);
			}
		}
	}
}
ll solve(const vector<node*>&adj,const vector<ll>&v)
{
	ll mn = loo;
	for (int i = 0; i < adj.size(); i++)
	{
		ll num = adj[i]->dis[0] + adj[i]->dis[1] + adj[i]->dis[2];
		if(num<=v.size()&&num>0)
		mn = min(mn, v[num - 1] + (adj[i]->dis[1]!=0?v[adj[i]->dis[1]-1]:0));
	}
	return mn;
}
int main()
{
	init();
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m, a, b, c;
		cin >> n >> m >> a >> b >> c;
		a--, b--, c--;
		vector<node*>adj(n);
		for (int i = 0; i < n; i++) adj[i] = new node(i + 1);
		vector<ll>v(m);
		for (auto& it : v) cin >> it;
		sort(v.begin(), v.end());
		for (int i = 1; i < m; i++)
			v[i] += v[i - 1];
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			u--, v--;
			adj[u]->neighbour.push_back(adj[v]);
			adj[v]->neighbour.push_back(adj[u]);
		}
		if (a == b && b == c)
		{
			cout << 0 << endl;
			continue;
		}
		bfs(adj[a], 0), bfs(adj[b], 1), bfs(adj[c], 2);
		
		ll ans = solve(adj, v);
		cout << ans << endl;
	}
	return 0;
}