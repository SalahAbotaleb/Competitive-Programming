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

int main()
{
	init();
	int tc;
	cin >> tc;
	vector<int>prim;
	primes(prim);
	while (tc--)
	{
		int n;
		cin >> n;
		int amoun;
		for (int i = 0; i < prim.size(); i++)
		{
			if (n % prim[i] == 0)
				amoun = prim[i];
		}
		int l1 = amoun-1;
		int l2 = amoun-1;
		for(int i=0;i<n;i++)
			for (int j = 0; j < n; j++)
			{
				if (i <= l1 && j <= l2 && i>l1-amoun && j>l2-amoun)
					cout << 1 << " \n"[j+1 == n];
				else
					cout << 0 << " \n"[j + 1 == n];
				if (i == l1 && j == l2)
					l1 += amoun, l2 += amoun;
			}
	}

	return 0;
}