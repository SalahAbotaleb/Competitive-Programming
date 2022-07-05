#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{

	int n,d;
	long long sum = 0;
	cin >> n >> d;
	vector <int> v(n);
	for (auto& x : v) cin >> x;
	for (auto it = v.begin(); it != v.end(); it++)
	{
		if (v.end() - it < 3)
			break;
		long long idx = upper_bound(v.begin(), v.end(), *it + d)-v.begin()-1;
		idx -= (it - v.begin());
		sum += ((idx) * (idx - 1)) / 2;
	}
	cout << sum << endl;
	return 0;
}