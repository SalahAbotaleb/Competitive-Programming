#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <fstream>
#define ll long long
using namespace std;
bool isok(int cr, int cc,  int mskc, int rd, int ld)
{
	if (mskc & (1 << cc))
		return 0;
	if (rd & (1 << (cr + cc)))
		return 0;
	if (ld & (1 << (7 - cc + cr)))
		return 0;
	return 1;
}
vector<string> s;
int cnt = 0;
void queen(int cr,int cc,int mskr, int mskc, int rd, int ld,int mat[8][8])
{
	if (cr == 8)
	{
		s.push_back("");
		for (int j = 0; j < 8; j++)
			for (int i = 0; i < 8; i++)
				if (mat[i][j] == 1)
					s[cnt] += to_string(i+1);
		cnt++;
		return;
	}
	if(mskr&(1<<cr))
		queen(cr + 1, 0, mskr , mskc , rd , ld , mat);

		for (int j = 0; j < 8; j++)
		{
			if (isok(cr, j, mskc, rd, ld))
			{
				mat[cr][j] = 1;
				queen(cr+1, j,mskr |(1<<cr), mskc | (1 << j), rd | (1 << (cr + j)), ld | (1 << (7 - j + cr)), mat);
				mat[cr][j] = 0;
			}
		}
}
int main()
{
	int n;
	cin >> n;
	for (int k = 0; k< n; k++)
	{
	int mskr=0,mskc = 0, rd = 0, ld = 0;
	int mat[8][8] = { };
		cnt = 0;
		s.clear();
		int l, r;
		cin >> r >> l;
		l--, r--;
		mat[r][l] = 1;
		mskr |= (1 << r);
		mskc |= (1 << l);
		rd |= (1 << (r+l)); 
		ld |= (1 << (7 - l + r));
	queen(0, 0, mskr, mskc,rd,ld ,mat);
	sort(s.begin(), s.end());
	cout << "SOLN       COLUMN" << endl;
	cout << " #      1 2 3 4 5 6 7 8\n\n";
	for (int i = 0; i < s.size(); i++)
	{
		printf("%2d      ", i + 1);
		for(int j=0;j<8;j++)
			cout << s[i][j] << " \n"[j == 7];
	if (i == s.size()-1 && k!=n-1)
		cout << endl;
	}
	}
	return 0;
}