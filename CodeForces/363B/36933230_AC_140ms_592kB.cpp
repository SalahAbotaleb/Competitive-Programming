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
	int n, k;
	cin >> n>>k;
	vector<int>v(n+1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i <= n; i++)
		v[i] += v[i - 1];
	int sum = INT_MAX;
	int idx = 0;
	for (int i = 1; i + k-1 <= n; i++)
	{
		if (v[i + k-1] - v[i - 1] < sum)
		{
			idx = i;
			sum = v[i + k-1] - v[i - 1];
		}
	}
	cout << idx << endl;
	return 0;
}