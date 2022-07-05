#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <fstream>
using namespace std;
struct dat
{
	int x=0;
	int y=0;
	int z=0;
	dat(int i, int j, int k)
	{
		x = i, y = j, z = k;
	}
	bool operator < (dat& dt)
	{
		if (x < dt.x)
			return 1;
		else
		{
			if (x > dt.x)
				return 0;
			else
			{
				return y < dt.y;
			}
		}
	}
};
int main()
{
	int n;
	cin >> n;
	ofstream fout("test.txt");
	while (n--)
	{
		int a, b, c;
		int x, y, z;
		cin >> a >> b >> c;
		x = -1, y = -1, z = -1;
		int mx = max({ a,b,c });
		int sqr = 0;
		vector <dat> v;
		for (int i = 0; i <= mx; i++)
			if (i * i <= mx)
				sqr = i; 
		for (int i = -sqr; i * i <= mx; i++)
		{
			for (int j = -sqr; j * j <= mx; j++)
			{
				for (int k = -sqr; k * k <= mx; k++)
				{
					if ((i + j + k == a) && (i * j * k == b) && (i * i + j * j + k * k == c))
					{
						if(i!=j && j!=k && i!=k)
						{
							x = i, y = j, z = k;
							v.push_back({ i,j,k });
						}
					}
				}
			}
		}
		sort(v.begin(), v.end());
		if (x == -1)
			cout << "No solution." << endl;
		else
			cout << v[0].x << " " << v[0].y << " " << v[0].z << endl;
	}
	return 0;
}