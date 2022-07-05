#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
using namespace std;
bool fnd(int tot, int idx,int arr[],int opr,string s="")
{
	if (tot == 23 && opr == 4)
		return 1;
	if (opr == 4)
		return 0;
	bool a = fnd(tot + arr[idx], idx + 1, arr,opr+1,s+"+");
	bool b = fnd(tot - arr[idx], idx + 1, arr,opr+1,s+"-");
	bool c = fnd(tot * arr[idx], idx + 1, arr,opr+1,s+"*");
	return a || b || c;
}
int main()
{
	int a, b, c, d, e;
	while (cin >> a >> b >> c >> d >> e && a + b + c + d + e)
	{
		int arr[5] = { a,b,c,d,e }; 
		bool ok = 0;
		sort(arr, arr + 5);
		do {
			if (fnd(arr[0], 1, arr, 0))
				ok = 1;
		} while (next_permutation(arr, arr + 5));
		if (ok)
			cout << "Possible" << endl;
		else
			cout << "Impossible" << endl;
	}
	return 0;
}