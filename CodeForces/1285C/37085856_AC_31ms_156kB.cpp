#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#define ll long long
using namespace std;
const int N = 1e9 + 7;
int fast_exp(ll b, int p)
{
	int ans = 1;
	while (p > 0)
	{
		if (p & 1)
			ans = ((ans % N) * (b % N)) % N;
		b = ((b % N) * (b % N)) % N;
		p >>= 1;
	}
	return ans;
}
void primes(vector<ll>& v,ll n)
{
	ll N = n;
	for (ll i = 2; i * i <= N; i++)
	{
		ll ans = 1;
		while (n % i == 0)
		{
			ans *= i;
			n /= i;
		}
		if(ans!=1)
			v.push_back(ans);
	}
	if (n > 0) v.push_back(n);
}
void pairs(const vector<ll>& v, vector<pair<ll, ll> >& ans, int idx=0, ll ans1 = 1, ll ans2 = 1)
{
	if (idx == v.size())
	{
		ans.push_back({ ans1,ans2 });
		return;
	}
	pairs(v, ans, idx + 1, ans1 * v[idx], ans2);
	pairs(v, ans, idx + 1, ans1, ans2*v[idx]);
}
int main()
{
	ll n;
	cin >> n;
	vector<ll>v;
	primes(v, n);
	sort(v.begin(), v.end());
	if (v.size() == 1)
	{
		cout << v[0] << " " << 1 << endl;
		return 0;
	}
	vector<pair<ll, ll> >ans;
	pairs(v, ans);
	sort(ans.begin(), ans.end(), [](pair<ll, ll>& v1, pair<ll, ll>& v2)
		{
			return max(v1.first, v1.second) < max(v2.first, v2.second);
		});
	cout << ans[0].first << " " << ans[0].second << endl;
	return 0;
}