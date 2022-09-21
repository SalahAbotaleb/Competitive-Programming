#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#define ll long long
using namespace std;
const int N= 1e9+7;
int fast_exp(ll b,int p)
{
	int ans = 1;
	while (p>0)
	{
		if (p & 1)
			ans = ((ans % N) * (b % N)) % N;
		b = ((b % N) * (b % N)) % N;
		p >>= 1;
	}
	return ans;
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int a, b;
		cin >> a >> b;
		cout << fast_exp(a, b) << endl;
	}
	return 0;
}