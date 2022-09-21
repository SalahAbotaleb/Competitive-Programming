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
	string s;
	cin >> s;
	char mn[500000+1];
	mn[0] = s[0];
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] < mn[i - 1])
		{
			mn[i] = s[i];
		}
		else
			mn[i] = mn[i - 1];
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (i == 0)
			cout << "Mike" << endl;
		else
		{
			string a,b; a.push_back(mn[i - 1]);
			a.push_back(s[i]);
			b.push_back(s[i]);
			if (a > b)
				cout << "Mike" << endl;
			else
				cout << "Ann" << endl;
		}
	}
	return 0;
}