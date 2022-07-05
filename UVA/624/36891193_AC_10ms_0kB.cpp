#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
void cd(vector<int>& v, int sz, int tot, int msk, int& mskg, int& totg,int idx,int m)
{
	if (tot > sz)
		return;
	if (tot > totg)
	{
		totg = tot;
		mskg = msk;
	}
	if (idx >= m)
		return;
	cd(v, sz, tot + v[idx], msk | (1 << idx), mskg, totg, idx + 1, m);
	cd(v, sz, tot , msk , mskg, totg, idx + 1, m);
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> v(m);
		for (auto& x : v) cin >> x;
		int msk = 0, total = 0;
		cd(v, n, 0, 0, msk, total, 0, m);
		for (int i = 0; i < 20; i++)
		{
			if (msk & (1 << i))
				cout << v[i] << " ";
		}
		cout << "sum:" << total << endl;
	}
	return 0;
}