#include<iostream>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#define MAX 10000
using namespace std;
int main()
{
	int n;
	while (cin >> n, n != 0)
	{
		int x;
		int arr[MAX];
		while (cin >> x, x != 0)
		{
			queue<int> q;
			stack<int> s;
			int flag = 1;
			q.push(1);
			arr[0] = x;
			for (int i = 1; i < n; i++)
			{
				cin >> x;
				arr[i] = x;
				q.push(i + 1);
			}
			for (int i = 0; i < n; i++)
			{
				if (!q.empty() && arr[i] == q.front())
				{
					q.pop();
				}
				else
				{
				if (!s.empty() && arr[i] == s.top())
						s.pop();
					else
					{
						while (!q.empty()&& q.front() != arr[i])
						{
							int x=q.front();
							s.push(x);
							q.pop();
						}
						if (!q.empty() && q.front() == arr[i])
						{
							q.pop();
						}
						else
						{
							flag = 0;
							break;
						}
					}
				}
			}
			if (flag)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		cout << endl;
	}
	return 0;
}