#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
	map<int, int> mp;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		mp[x]++;
	}
	int sum=0;
	for (auto m : mp)
	{
		sum += (m.second - m.first>=0?m.second - m.first:m.second);
	}
	cout << sum << endl;
	return 0;
}