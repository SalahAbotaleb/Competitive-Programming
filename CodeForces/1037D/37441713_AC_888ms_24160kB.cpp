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
struct node
{
	int idx = -1;
	int par = -1;
	bool vis = 0;
	ll dis = loo;
	vector<node*>negihbour;
};
vector<int>ans;
void bfs(node* src)
{
	queue<node*>q;
	src->dis = 0;
	q.push(src);
	while (!q.empty())
	{
		auto curr = q.front();
		int dis = q.front()->dis;
		q.pop();
		ans.push_back(curr->idx);
		for (auto neigh : curr->negihbour)
		{
			if (dis+1 < neigh->dis)
			{
				neigh->dis = dis+1;
				neigh->par = curr->idx;
				q.push(neigh);
			}
		}
	}
}
int main()
{
	int n, m;
	cin >> n ;
	vector<node*>adj(n);
	vector<int>vv;
	for (int i = 0; i < n; i++)
	{
		adj[i] = new node;
		adj[i]->idx = i + 1;
	}
	for (int i = 0; i <n-1 ; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u]->negihbour.push_back(adj[v]);
		adj[v]->negihbour.push_back(adj[u]);
	}
	unordered_map <int, int> mp;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		vv.push_back(x);
		mp[x] = i;
	}
	for (int i = 0; i < n; i++)
		sort(adj[i]->negihbour.begin(), adj[i]->negihbour.end(), [&](node* a, node* b) {
		return mp[a->idx] < mp[b->idx];
			});
	bfs(adj[0]);
	if(vv.size()!=ans.size())
		return cout << "NO\n", 0;
	for (int i = 0; i < n; i++)
	{
		if (vv[i]!=ans[i])
			return cout << "NO\n", 0;

	}
	cout << "YES\n";
	return 0;
}