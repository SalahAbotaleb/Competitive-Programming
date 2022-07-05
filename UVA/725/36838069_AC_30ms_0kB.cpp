#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <fstream>
using namespace std;
int digcoun(int n)
{
	int c = 0;
	while (n > 0)
	{
		c++;
		n /= 10;
	}
	return c;
}
int getmx(int n)
{
	int st = 0;
	int end = 54321;
	while (st < end)
	{
		int mid = (st + end) / 2;
		if (digcoun(mid * n) <= 5)
		{
			st = mid+1;
		}
		else
		{
			end = mid;
		}
	}
	return end;
}
int main()
{
	//ofstream fout("test.txt");
	int n;
	bool fir = 1;
	while (cin >> n,n)
	{
		int t = getmx(n);
		bool null = 1;
			if (fir) fir = 0;
			else cout << endl;
		for (int i = 1234; i < t; i++)
		{
			int x = n * i;
			int cp = i;
			int ok = 0;
			int msk1 = 0;
			int msk2 = 0;
			while (x > 0)
			{
				msk1 |= 1 << (x % 10);
				x /= 10;
			}
			if(digcoun(i) != 5)
				msk2 |= (1 << 0);
			while (cp > 0)
			{
				msk2 |= 1 << (cp % 10);
				cp /= 10;
			}
			//cout << n * i << "  " << i << endl;
			for (int i = 0; i < 31; i++)
			{
				bool dig1 = msk1 & (1 << i);
				bool dig2 = msk2 & (1 << i);
				//cout << dig1 << "  " << dig2 << endl;
				if (dig1 != dig2)
					ok++;
			}
			if (ok == 10)
			{
				null = 0;
				if(digcoun(i)!=5)
				cout << n * i << " / " << 0 << i << " = " << n << endl;
				else
					cout << n * i << " / " << i << " = " << n << endl;
			}
		}
		if(null)
		cout << "There are no solutions for "<<n<<"." << endl;
	}
	return 0;
}