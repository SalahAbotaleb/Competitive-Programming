#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <fstream>
using namespace std;
int main()
{
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int arr[3];
	arr[2] = max({a,b,c});
	arr[0] = min({a,b,c});
	arr[1] = a + b + c - arr[0] - arr[2];
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < n/arr[2]+1; i++)
	{
		for (int j = 0; j < n/arr[1]+1; j++)
		{
			for (int k = 0; k < n / arr[0]+1; k++)
			{
				if (arr[0] * k + arr[1] * j + arr[2] * i == n)
				{
					sum = max(sum,k + j + i);
					break;
				}
			}
			if (sum)
				break;
		}
		if (sum)
			break;
	}
	int sum2 = 0;
	for (int i = 0; i < n / arr[1] + 1; i++)
	{
		for (int j = 0; j < n / arr[2] + 1; j++)
		{
			for (int k = 0; k < n / arr[0] + 1; k++)
			{
				if (arr[0] * k + arr[2] * j + arr[1] * i == n)
				{
					sum = max(sum, k + j + i);
					sum2 = sum;
					break;
				}
			}
			if (sum2)
				break;
		}
		if (sum2)
			break;
	}
	cout << sum << endl;
}