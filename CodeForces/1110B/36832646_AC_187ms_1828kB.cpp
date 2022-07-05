#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v(n);
	vector<int> diff(n);
	for (auto& x : v) cin>>x;
	int len = 0;
	for (int i = 1; i < n; i++)
	{
		diff[i - 1] = v[i] - v[i - 1]-1;
		len += diff[i - 1];
	}
	sort(diff.begin(), diff.end());
	for (int i = 0; i < k - 1; i++)
	{
		len -= diff.back();
		diff.pop_back();
	}
	cout << len+n  << endl;
	return 0;
}