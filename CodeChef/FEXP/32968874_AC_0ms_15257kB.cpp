#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod=1e9+7;
int fast_pow(int base,int p)
{
    ll ans=1;
    while(p>0)
    {
        if(p&1)
            ans=(1ll *(ans%mod) * (base%mod))%mod;
        p/=2;
        base=(1ll *(base%mod) * (base%mod))% mod;
    }
    return ans;
}
int main()
{

    int tc;
    cin>>tc;
    while(tc--)
    {
        int p,base;
        cin>>base>>p;
        cout<<fast_pow(base,p)<<endl;
    }

    return 0;
}
