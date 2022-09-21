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
int arr[N];
void primes()
{
	arr[0] = arr[1] = 1;
	for (int i = 2; i * i < N; i++)
	{
		if (arr[i] == 0)
		{
			for (int j = i + i; j < N; j += i)
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
		string s, t;
		cin >> s >> t;
		int p1 = 0;
		int p2 = 0;
		bool ok = 1;
		if (t.size() < s.size())
			ok = 0;
		while (ok && p1 < s.size() && p2 < t.size())
		{
			int l = 0;
			int r = 0;
			while (p1 + 1 < s.size() && s[p1] == s[p1 + 1])
				p1++,l++;
			while (p2 + 1 < t.size() && t[p2] == t[p2 + 1])
				p2++,r++;
			if (s[p1] != t[p2] || r<l)
				ok = 0;
			else
				p1++, p2++;
		}
		cout << (ok && p1 == s.size() && p2==t.size() ? "YES\n" : "NO\n");
	}
	return 0;
}