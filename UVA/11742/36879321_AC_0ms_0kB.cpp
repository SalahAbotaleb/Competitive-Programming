#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <fstream>
using namespace std;
int findidx(vector<int>& v,int n)
{
	int id = -1;
	for (int i = 0; i < v.size(); i++)
		if (v[i] == n)
		{
			id = i;
			break;
		}
	return id;
}
int main()
{
	int n, m;
	while (cin >> n >> m, n)
	{
		vector<int> v(n);
		vector<pair<pair<int, int>, int>> cons(m);
		for (int i = 0; i < n; i++)
			v[i] = i;
		for (int i = 0; i < m; i++)
			cin >> cons[i].first.first >> cons[i].first.second >> cons[i].second;
		int cnt = 0;
		do {
			bool ok = 1;
			for (int i = 0; i < m; i++)
			{
				int idx1 = findidx(v, cons[i].first.first);
				int idx2 = findidx(v, cons[i].first.second);
				if (cons[i].second < 0)
				{
					if (abs(idx1 - idx2) < abs(cons[i].second))
					{
						ok = 0;
						break;
					}
				}
				else
				{
					if (abs(idx1 - idx2) > abs(cons[i].second))
					{
						ok = 0;
						break;
					}
				}
			}
			cnt += ok;
		} while (next_permutation(v.begin(), v.end()));
		cout << cnt << endl;
	}
	return 0;
}
