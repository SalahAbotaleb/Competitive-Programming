#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
     int n,k;
     cin>>n>>k;
     int a[n],b[n];
     int s=0;
     for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
        s+=a[i];
    }
     for(int i=0;i<n;i++) scanf("%d",b+i);
     sort(a,a+n);
     sort(b,b+n,greater <int> ());
     for(int i=0;i<n&&k;i++)
     {
         if(b[i]>a[i])
         {
             k--;
             s-=a[i];
             s+=b[i];
         }
     }
     cout<<s<<endl;
    }
    return 0;
}
