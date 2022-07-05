#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
using namespace std;
int primes[1000];
void pp()
{
	for (int i = 2; i < 1000; i++)
	{
		bool p = 1;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
				p = 0;
		}
		primes[i] = p;
	}
}

void prime(int n, int idx,vector<int>v={1},int msk=2)
{
	if (idx == n-1)
	{
		if (primes[v[v.size() - 1] + 1])
		{
			for (int i = 0; i < v.size(); i++)
				cout << v[i] << " \n"[i == v.size() - 1];
		}
		return;
	}
	for (int i = 2; i <= n; i++)
	{
		if (msk & (1 << i))
			continue;
		if (primes[v[idx] + i])
		{
			v.push_back(i);
			prime(n, idx + 1, v,msk|(1<<i));
			v.pop_back();
		}
	}
}
int main()
{
	int cnt = 0;
	int n;
	pp();
	while (cin >> n)
	{
		if (cnt)
			cout << endl;
		printf("Case %d:\n", ++cnt);
		prime(n, 0);
	}
}