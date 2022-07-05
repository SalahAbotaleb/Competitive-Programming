#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll seive(ll n)
{
    for(ll i=3;i*i<=n;i+=2)
    {
        ll k=n;
        while(k%i==0)
        {
            return i;
        }
    }
    return n;
}
int main()
{

    ll n;
    cin>>n;
    ll c=0;
    while(n>0)
    {
        if(n%2==0)
        {
            c+=(n/2);
            break;
        }
        ll res=seive(n);
        //cout<<res<<endl;
        n-=res;
        c++;
    }
    cout<<c<<endl;


    return 0;
}

