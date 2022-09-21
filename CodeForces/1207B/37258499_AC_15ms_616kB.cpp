#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#define ll long long
using namespace std;
const int N = 1e5;
int arr[N];
void primes(vector<int>&v)
{
	arr[0] = arr[1] = 1;
	for (int i = 2; i*i < N; i++)
	{
		if (arr[i] == 0)
		{
			v.push_back(i);
			for (int j = i; j < N; j+=i)
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
bool valid(int x, int y, int n, int m)
{
	return x >= 0 && x < n&& y >= 0 && y < m;
}
int main()
{
	init();
	int n,m;
	cin >> n>>m;
	int** mat = new int*[n];
	for (int i = 0; i < n; i++)
		mat[i] = new int[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];
	vector<pair<int, int>>v;
	vector<pair<int, int> >dir = { {0,0},{0,1},{1,0},{1,1} };
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			int issqr = 0;
			for (auto it : dir)
				if (valid(i+it.first, j+it.second, n, m) && mat[i+it.first][j+it.second])
					issqr++;
			if (issqr == 4)
				v.push_back({ i,j });
		}
	int** mat2 = new int* [n];
	for (int i = 0; i < n; i++)
		mat2[i] = new int[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mat2[i][j] = 0;
	for (auto it : v)
	{
		int begi = it.first, begj = it.second;
		for (auto it : dir)
			mat2[begi + it.first][begj + it.second] = 1;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (mat[i][j] != mat2[i][j])
			{
				cout << -1 << endl;
				return 0;
			}
	cout << v.size() << endl;
	for (auto it : v)
		cout << it.first+1 << " " << it.second+1 << endl;

	return 0;
}