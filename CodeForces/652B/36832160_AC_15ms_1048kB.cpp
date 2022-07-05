#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int>v(n);
	vector<int>v2(n,0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int mid = n / 2 + (n % 2);
	int xx;
	for (int i = 0,j=0; i < n; i += 2,j++)
	{
		v2[i] = v[j];
		xx = j;
	}
	for (int i = 1, j = xx+1; i < n; i += 2, j++)
	{
		v2[i] = v[j];
	}
	for (auto& x : v2) cout << x << " ";
	cout << endl;
}