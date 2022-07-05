#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#define ll long long
using namespace std;
int main()
{
	vector<pair<pair<int,int>, int>>mp;
	int n, m, k;
	cin >> n>>m>>k;
	vector <ll> v(n+1);
	vector<ll> sum(n+2, 0);
	vector <ll> freq(m + 2, 0);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	mp.push_back({ });
	for (int i = 0; i < m; i++)
	{
		int l, r, v;
		cin >> l >> r >> v;
		mp.push_back({ {l,r},v });
	}
	for (int i = 0; i < k; i++)
	{
		int l, r;
		cin >> l >> r;
		freq[l]++;
		freq[r + 1]--;
	}
	for (int i = 1; i <= m; i++)
		freq[i] += freq[i-1];
	for (int i = 1; i <= m; i++)
	{
		int l = mp[i].first.first;
		int r = mp[i].first.second;
		int fre = freq[i];
		sum[l] += mp[i].second * freq[i];
		sum[r+1] -= mp[i].second * freq[i];
	}
	for (int i = 1; i <= n; i++)
		sum[i] += sum[i - 1];
	for (int i = 1; i <= n; i++)
		cout << v[i] + sum[i] << " ";
	return 0;
}