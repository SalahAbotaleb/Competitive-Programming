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
#include <cassert>
#define ll long long
using namespace std;
const int N = 1e5;
int arr[N];
const int oo = 0x3f3f3f3f;
const ll loo = 0x3f3f3f3f3f3f3f3f;
void primes(vector<int>& v)
{
	arr[0] = arr[1] = 1;
	for (int i = 2; i * i < N; i++)
	{
		if (arr[i] == 0)
		{
			v.push_back(i);
			for (int j = i; j < N; j += i)
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
struct node
{
	int id = -1;
	bool typ; //0 boy 1 girl
	int dis = oo;
	vector<node*>neigh;
};
void rst(vector<node*>& adj)
{
	for (auto& it : adj) it->dis = oo;
}
/*int bfs(node* src)
{
	queue<node*>q;
	vector<pair<int, int>> v; //msk and count
	q.push(src);
	src->dis = 0;
	int cnt = 0;
	while (!q.empty())
	{
		int msk = 0;
		auto curr = q.front();
		q.pop();
		int c = 1;
		if (curr->dis == 3)
			break;
		int ty = curr->typ;
		cnt++;
		for (auto it : curr->neigh)
		{
			if (curr->typ == 1 && it->typ == 0)
				msk |= (1 << it->id),c++;
			if (it->typ == 1 - ty && curr->dis + 1 < it->dis)
			{
				it->dis=curr->dis + 1;
				q.push(it);
			}
		}
		if (curr->typ == 1 && v.size() == 0)
		{
			v.push_back({ msk,c });
		}
		else
		{
			bool ok = 1;
			for (auto &it : v)
			{
				int cmsk = it.first;
				if (msk != cmsk)
					ok = 0;
				else
				{
					it.second++;
					break;
				}
			}
			if (!ok)
			{
				v.push_back({ msk,c });
			}
		}
	}
	int mx = 0;
	for (auto it : v)
		mx = max(mx, it.second);
	return mx;
}*/
ll __gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	return __gcd(b, a % b);
}
int main()
{
	int n;
	cin >> n;
	vector<ll>v(n);
	for (auto &it : v) cin >> it;
	int mx = *max_element(v.begin(), v.end());
	for (int i = 0; i < n; i++)
		v[i] = mx - v[i];
	vector<ll>ans;
	set<int>s;
	bool ok = 1;
	for (auto it : v)
		if (it != 0)
			ans.push_back(it);
	ll val = 0;
	ll tot = 0;
	if (ans.size() >= 2)
	{

		ll gg = ans[0];
		for (int i = 1; i < ans.size();i++)
			gg = __gcd(gg, ans[i]);
		if (gg == 1)
			ok = 0;
		else
		{
			for (int i = 0; i < ans.size(); i++)
			{
				if (ans[i] % gg != 0)
					ok = 0;
				val += ans[i] / gg;
				tot += ans[i];
			}
		}
	}
	else
		ok = 0;
	if (ok)
		cout << val <<" " << tot / val  << endl;
	else
	{
		if(ans.size()==0)
		cout << 0 << " " << 0 << endl;
		else
		{
			if (ans.size() == 1)
			{
				return cout << 1 << " " << ans[0], 0;
			}
			ll sum = 0;
			for (int i = 0; i < ans.size(); i++)
			{
				sum += ans[i];
			}
			cout << sum << " " << 1 << endl;
		}
	}
}