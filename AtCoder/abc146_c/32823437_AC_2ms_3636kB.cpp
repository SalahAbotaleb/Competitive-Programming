#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,x;
bool ok(ll n)
{
    ll nn=n;
    int c=0;
    while(nn>0)
    {
        nn/=10;
        c++;
    }
    //cout<<"c:  "<<c<<endl;
    if((ll)a*n+(ll)b*c<=x)
        {
            //cout<<"yes"<<endl;
            return 1;
        }
        //cout<<"no"<<endl;
    return 0;
}
ll bs(ll l=0,ll r=1e9)
{
    ll mid;
    while(l<r)
    {
        mid=l+((r-l)>>1)+1;
        //cout<<l<<"  "<<mid<<"  "<<r<<endl;
        if(ok(mid))
        {

            l=mid;
        }
        else
            r=mid-1;
    }
    return l;
}
int main()
{
    cin>>a>>b>>x;
    cout<<bs()<<endl;

    return 0;
}
