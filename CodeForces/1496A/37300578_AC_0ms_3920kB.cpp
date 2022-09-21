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
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		string s1 = s.substr(0, q);
		string s3 = s;
		reverse(s3.begin(),s3.end());
		string s2 = s3.substr(0, q);
		if ((q == 0 || s1==s2)&&2*q!=n )
			cout << "YES\n";
		else
			cout <<"NO\n";
	}
	
	return 0;
}