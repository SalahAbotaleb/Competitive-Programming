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
const int N = 1e6+5;
int arr[N];
void primes()
{
	arr[0] = arr[1] = 1;
	for (int i = 2; i * i < N; i++)
	{
		if (arr[i] == 0)
		{
			for (int j = i+i; j < N; j += i)
			{
				arr[j] = 1;
			}
		}
	}
}
struct num
{
	int id;
	int count = 2;
	int prev = 1;
	int mdiff = INT_MAX;
	num(int i)
	{
		id = i;
	}
	void diff()
	{
		mdiff = min(mdiff, id - prev);
	}
	bool operator < (const num& n) const
	{
		if (mdiff == n.mdiff)
			return id < n.id;
		return mdiff < n.mdiff;
	}
};
void divs(vector<num>&v)
{
	for (int i = 2; i*i <N; i++)
	{
		for (int j = i+i; j < N; j+=i)
		{
			v[j].count++;
			v[j].mdiff = min(v[j].mdiff,i-v[j].prev);
			v[j].prev = i;
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
int main()
{
	init();
	int tc;
	cin >> tc;
	primes();
	vector<int>v;
	for (int i = 2; i < N; i++)
		if (!arr[i])
			v.push_back(i);
	while (tc--)
	{
		int n;
		cin >> n;
		int x = n+1;
		int i1, i2;
		while (true)
		{
			 i1 = *lower_bound(v.begin(), v.end(), x);
			auto it = lower_bound(v.begin(), v.end(), i1 + n);
			if (it != v.end())
			{
				i2 = *it;
				break;
			}
			x++;
		}
		cout << i1 * i2 << endl;
	}
	return 0;
}