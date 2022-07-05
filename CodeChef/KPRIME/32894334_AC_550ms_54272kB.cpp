#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e7+7;
int arr[N];
void seive(ll n=N)
{
    arr[0]=arr[1]=1;
    for(ll i=2;i<=n;i++)
    {
        if(!arr[i])
        for(ll j=i;j<n;j+=i)
        {
            ll k=j;
            ll e=0;
            while(k%i==0)
            {
                k/=i;
                e++;
            }
            if(e!=0)
                arr[j]++;
        }
    }
}
int main()
{

    seive(1e5+5);
    int tc;
    cin>>tc;
    while(tc--)
    {
    int a,b,k;
    cin>>a>>b>>k;
    int c=0;
    for(int i=a;i<=b;i++)
       {
           if(arr[i]==k)
            c++;
       }
    cout<<c<<endl;
    }

    return 0;
}

