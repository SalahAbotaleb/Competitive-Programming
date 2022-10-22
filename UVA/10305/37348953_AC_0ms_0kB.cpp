#include<iostream>
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
#define ll long long
using namespace std;
const int N = 1e5;
struct node
{
	int id = -1;
	bool vis = 0;
	vector<node*>neighbour;
};
void dfs(node* curr,stack<int>&s)
{
	curr->vis = 1;
	int mx=0;
	for (auto it : curr->neighbour)
	{
		if (it->vis == 0)
			dfs(it,s);
	}
	s.push(curr->id);
}
int main()
{
	//ofstream fout("test.txt");
		int n,m;
		while (cin >> n >> m && n+m)
		{
			vector<node*>adj(n);
			for (int i = 0; i < n; i++)
			{
				adj[i] = new node;
				adj[i]->id = i + 1;
			}
			for (int i = 0; i < m; i++)
			{
				int v,u;
				cin >>u>>v;
				u--, v--;
				adj[u]->neighbour.push_back(adj[v]);
			}
			int mx = 0;
			stack<int>s;
			for (auto it : adj)
			{
				if (!it->vis)
					dfs(it,s);
			}
			while (!s.empty())
			{
				cout << s.top() << " \n"[s.size() == 1];
				s.pop();
			}
		}
	return 0;
}