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
using namespace std;
const int N = 1e6 + 5;
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int oo = 0x3f3f3f3f;
int dx[] = { 1,-1,0,0,1,1,-1,-1 };
int dy[] = { 0,0,1,-1,1,-1,1,-1 };
int bfs(int idxi, int idxj, int n ,int mat[25][25])
{
	mat[idxi][idxj] = 2;
	int cnt = 0;
	queue<pair<int, int>>q;
	q.push({ idxi,idxj });
	while (!q.empty())
	{
		cnt++;
		int ci = q.front().first;
		int cj = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int ni = ci + dx[i];
			int nj = cj + dy[i];
			if (ni<n && ni>-1 && nj<n && nj>-1 && mat[ni][nj]==1)
			{
				mat[ni][nj] = 2;
				q.push({ ni,nj });
			}
		}
	}
	return cnt;
}
int main()
{
	int tc;
	cin >> tc;
	for(int K=0;K<tc;K++)
	{
		string s;
		int mat[25][25];
		cin >> s;
		vector<string>v(s.size());
		v[0] = s;
		for (int i = 1; i < s.size(); i++)
			cin >> v[i];
		for (int i = 0; i < s.size(); i++)
			for (int j = 0; j < s.size(); j++)
			{
				mat[i][j] = v[i][j] - '0';
			}
		int cnt = 0;
		for (int i = 0; i < s.size(); i++)
			for (int j = 0; j < s.size(); j++)
				if (mat[i][j] == 1)
					cnt=max(cnt,bfs(i, j, s.size(), mat));
		cout << cnt << endl;
		if (K != tc - 1)
			cout << endl;
	}
	return 0;
}