#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll res=n;
    for(ll i=1;i*i<=n;i++)
    {
     if(n%i==0 && __gcd(n/i,i)==1)
     {
         res=min(res,max(i,n/i));
     }
    }
    cout<<n/res<<" "<<res<<endl;

    return 0;
}
