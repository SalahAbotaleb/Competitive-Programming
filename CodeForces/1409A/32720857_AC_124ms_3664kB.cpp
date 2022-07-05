#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
     int a,b;
     cin>>a>>b;
     int d=abs(a-b);
     int c=0;
     for(int i=10;i>=1;i--)
     {
         int n=d/i;
         c+=d/i;
         //cout<<d/i<<endl;
         d-=n*i;
     }
     cout<<c<<endl;
    }
    return 0;
}
