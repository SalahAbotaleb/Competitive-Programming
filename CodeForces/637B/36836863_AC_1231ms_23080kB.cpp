#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int main()
{
	map<string, int> mp;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string x; cin >> x;
		mp[x] = i;
	}
	vector<pair<string, int> >v;
	for (auto m : mp) v.push_back({ m.first,m.second });
	sort(v.begin(), v.end(), [](pair<string, int> a, pair<string, int> b) {
		return a.second > b.second;
		});
	for (auto m : v) cout << m.first << endl;
	return 0;
}