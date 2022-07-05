#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int i,int val)
{
	return i > val;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector <int> v1(n);
	vector <int> v2(m);
	for (auto& x : v1) cin >> x;
	for (auto& x : v2) cin >> x;
	sort(v1.begin(), v1.end());
	for (int i = 0; i < v2.size(); i++)
	{
		int num = v2[i];
		int start = 0;
		int end = v1.size() - 1;
		int mid;
		while (start < end)
		{
			mid = (start + end) / 2;
				if (!cmp(v1[mid],num))
				{
					start = mid+1;
				}
				else
					end = mid ;
		}
		cout << end +(v1.back()<=num?1:0) << " ";
	}
	return 0;
}