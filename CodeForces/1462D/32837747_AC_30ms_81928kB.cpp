#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e7+7;
ll arr[N];
int n;
ll sum;
bool ok(int x)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        c+=arr[i];
        if(c==x)
            c=0;
        if(c>x)
            return 0;
    }
    return 1;
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
    sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
   // cout<<"sum  "<<sum<<endl;
    int m=sum;
    for(int i=1;i*i<=sum;i++)
    {
        if(sum%i==0)
        {
            if(ok(i)&&i<m)
                m=i;
            if(ok(sum/i)&&sum/i<m)
                m=sum/i;

        }
    }
    cout<<n-sum/m<<endl;


    }


    return 0;
}
