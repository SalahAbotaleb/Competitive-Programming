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
	const int N = 1e5 + 5;
	int arr[N]={ };
	for (int i = 2; i < N; i += 10)
		arr[i]++;
	for (int i = 3; i < N; i += 10)
		arr[i]++;
	for (int i = 9; i < N; i += 10)
		arr[i]++;
	for (int i = 1; i < N; i++)
		arr[i] += arr[i - 1];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		cout << arr[r] - arr[l - 1] << endl;
	}
	return 0;
}