#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 20e4;
int vis[N];
int bfs(int n,int m)
{
	queue<int> q;
	q.push(n);
	vis[n] = 1;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		if (node == m)
			return vis[m];
		for (int i = 0; i < 2; i++)
		{
			int nval;
			if (i == 0)
				nval = node * 2;
			else
				nval = node - 1;
			if (nval<0 || nval>max(m,n) * 2)
				continue;
			if (vis[nval])
				continue;
			vis[nval] = vis[node] + 1;
			q.push(nval);
		}

	}
}
int main()
{
	int n,m;
	cin >> n >> m;
	cout<<bfs(n,m)-1;
	
	
	return 0;
}