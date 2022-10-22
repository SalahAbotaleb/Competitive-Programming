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
#define ll long long
using namespace std;
const int N = 1e5;
struct node
{
	int id = -1;
	bool vis = 0;
	vector<node*>neighbour;
};
int dfs(node* curr)
{
	curr->vis = 1;
	int mx=0;
	for (auto it : curr->neighbour)
	{
		if (it->vis == 0)
			mx=max(1+dfs(it),mx);
	}
	return mx;
}
int main()
{
	//ofstream fout("test.txt");
		int n;
		cin >> n;
		vector<node*>adj(n);
		vector<node*>root;
		for (auto& it : adj) it = new node;
		for (int i = 0; i < n; i++)
		{
			int v;
			cin>>v;
			if (v == -1)
			{
				root.push_back(adj[i]);
				continue;
			}
			v--;
			adj[v]->neighbour.push_back(adj[i]);
		}
		int mx = 0;
		for (auto it : root)
		{
			mx = max(mx, dfs(it));
		}
		cout << mx+1 << endl;
	return 0;
}