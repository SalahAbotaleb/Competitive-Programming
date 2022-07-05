#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#define ll long long
using namespace std;
vector <ll> v;
void fnd(int dig, int c4, int c7, ll num = 0)
{
	if (c4 + c7 >= dig)
	{
		if (c4 == c7)
			v.push_back(num);
	}
	if (c4 + c7 >= dig + 2)
		return;
	fnd(dig, c4 + 1, c7, num * 10 + 4);
	fnd(dig, c4, c7+1, num * 10 + 7);
}
int main()
{
	ll n;
	cin >> n;
	int cnt = 0;
	int cop = n;
	while (cop > 0)
	{
		cnt++;
		cop /= 10;
	}
	fnd(cnt, 0, 0, 0);
	sort(v.begin(), v.end());
	for(auto x:v)
	{
		if (x >= n)
		{
			cout << x << endl;
			break;
		}
	}
	return 0;
}