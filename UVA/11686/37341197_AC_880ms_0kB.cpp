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
#define ll long long
using namespace std;
const int N = 1e5;
struct node
{
	int id = -1;
	int vis = 0;
	int instack = 0;
	vector<node*>neighbour;
	int indeg = 0;
	node(int n)
	{
		id = n;
	}
};
void dfs(node* curr,node* prev ,bool& ok,stack<int>&s)
{
	curr->vis=1;
	curr->instack = 1;
	for (auto it : curr->neighbour)
	{
		if (!it->vis)
			dfs(it, curr, ok,s);
		else
			if (it->instack)
				ok = 0;
	}
	curr->instack = 0;
	s.push(curr->id);
}
int main()
{
	int n, m;
		
	while (cin >> n >> m && (n+m))
	{
		vector<node*>adj(n);
		for (int i = 0; i < n;i++) adj[i] = new node(i + 1);
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			u--, v--;
			adj[u]->neighbour.push_back(adj[v]);
			adj[v]->indeg++;
		}
		bool ok = 1;
		stack<int>s;
		for (auto it : adj)
			if (!it->indeg)
				dfs(it,it,ok,s);
		if (!ok || s.size()!=n)
			cout << "IMPOSSIBLE\n";
		else
			while (!s.empty())
			{
				cout << s.top() << endl;
				s.pop();
			}
	}
	return 0;
}