#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#define ll long long
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int>v(n);
	int even = 0, odd = 0;
	for (auto& x : v)
	{
		cin >> x;
		odd += (x % 2);
		even += (x % 2 == 0);
	}
	if(odd && even)
	sort(v.begin(), v.end());
	for (auto x : v) cout << x << " ";
	return 0;
}