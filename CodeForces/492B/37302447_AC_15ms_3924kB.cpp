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
	int n,l;
	cin >> n >>l;
	vector<int>v(n);
	for (auto& it : v) cin >> it;
	sort(v.begin(), v.end());
	int beg = 0;
	int mx = INT_MIN;
	for (int i = 1; i <v.size(); i++)
	{
		mx = max(mx, v[i] - v[i - 1]);
	}
	mx = max(mx, (*v.begin() - 0) * 2);
	mx = max(mx, (l - v.back())*2);
	cout << fixed << setprecision(10) << mx / 2.0 << endl;
	return 0;
}