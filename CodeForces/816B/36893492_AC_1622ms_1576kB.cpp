#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#define ll long long
using namespace std;
int arr[200002];
int arr2[200002];
int main()
{
	int n, k, q;
	cin >> n >> k >> q;
	for (int i = 0; i < n; i++)
	{
		int l; int r;
		cin >> l >> r;
		arr[l] += 1;
		arr[r + 1] -= 1;
	}
	for (int i = 1; i < 200002; i++)
		arr[i] += arr[i - 1];
	for (int i = 1; i < 200002; i++)
		if (arr[i] >= k)
			arr2[i] = 1;
	for (int i = 1; i < 200002; i++)
		arr2[i] += arr2[i - 1];
	for (int i = 0; i < q; i++)
	{
		int l, r;
		cin >> l >> r;
		cout << arr2[r] - arr2[l-1] << endl;
	}
	return 0;
}