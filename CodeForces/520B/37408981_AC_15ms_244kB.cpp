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
const int oo = 0x3f3f3f3f;
int dx[] = {2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,1,-1,2,2,-2,-2};
struct node
{
	int idx = -1;
	bool vis = 0;
	ll dis = loo;
	vector<node*>negihbour;
};
bool isvalid(int x, int y)
{
	return x<8 && x>-1 && y<8 && y>-1;
}

void bfs(int num,vector<int>&dis)
{
	queue<int>q;
	dis[num] = 0;
	q.push(num);

	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();
		int arr[2] = { curr * 2,curr - 1 };
		for (auto it : arr)
		{
			if (it >= 0 && it < 20005 && dis[curr] + 1 < dis[it])
			{
				dis[it] = dis[curr] + 1;
				q.push(it);
			}
		}
	
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int>v(20005, oo);
	bfs(n,v);
	cout << v[m] << endl;


	return 0;
}