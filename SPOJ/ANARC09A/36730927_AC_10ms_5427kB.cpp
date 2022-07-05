#include<iostream>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int main()
{
	int idx = 0;
	string s;
	while (getline(cin, s),s[0]!='-')
	{
		int on = 0;
		int num = 0;
		for (int i = 0; i < s.size(); i++)
		{
			
			if (s[i] == '{')
				on++;
			if (s[i] == '}')
			{
				if (on != 0)
				{
					on--;
				}
				else
				{
					num++;
					on++;
				}
			}

		}
		cout <<++idx<<". " << num + ceil(on / 2.0) << endl;
	}
	return 0;
}