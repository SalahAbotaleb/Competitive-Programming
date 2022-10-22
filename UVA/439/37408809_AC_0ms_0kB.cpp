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

int mat[8][8];
void bfs(int srci,int srcj)
{
	queue<pair<int,int>>q;
	mat[srci][srcj] = 0;
	q.push({srci,srcj});
	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();
		int x = curr.first;
		int y = curr.second;
		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (isvalid(nx,ny) && mat[x][y] + 1 < mat[nx][ny])
				mat[nx][ny]=mat[x][y]+1, q.push({nx,ny});
		}
	}
}
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				mat[i][j] = 100000;
		bfs(a[1]-'0'-1,a[0]-'a');
		cout << "To get from "<<a<<" to "<<b<<" takes "<< mat[b[1] - '0' - 1][b[0] - 'a'] <<" knight moves." << endl;
	}



	return 0;
}