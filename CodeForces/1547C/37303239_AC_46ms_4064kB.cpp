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
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, a, b;
		cin >> n >> a >> b;
		vector<int>v1;
		vector<int>v2;
		int cnt = 0;
		int mx = INT_MIN;
		for (int i = 0; i < a ; i++)
		{
			int x;
			cin >> x;
			if (x == 0)
				cnt++;
			else
				mx=max(mx,x);
			v1.push_back(x);
		}
		for (int i = 0; i < b; i++)
		{
			int x;
			cin >> x;
			if (x == 0)
				cnt++;
			else
				mx = max(mx, x);
			v2.push_back(x);
		}
		if (n + cnt < mx)
		{
			cout << -1 << endl;
			continue;
		}
		bool ok = 1;
		cnt = 0;
		int i1 = 0;
		int i2 = 0;
		vector<int>ans;
		while (true)
		{
			if (i1 < a && v1[i1] == 0)
			{
				cnt++;
				ans.push_back(v1[i1]);
				i1++;
				continue;
			}
			if (i2 < b && v2[i2] == 0)
			{
				cnt++;
				ans.push_back(v2[i2]);
				i2++;
				continue;
			}
			if (i1 < a && cnt+n >= v1[i1])
			{
				ans.push_back(v1[i1]);
				i1++;
				continue;
			}
			if (i2 < b && cnt+n >= v2[i2])
			{
				ans.push_back(v2[i2]);
				i2++;
				continue;
			}
			if (ans.size() == a + b)
				break;
			ok = 0;
			break;
		}
		if (!ok)
			cout << -1 << endl;
		else
			for (auto it : ans)
				cout << it << " ";
		cout << endl;
	}
	return 0;
}