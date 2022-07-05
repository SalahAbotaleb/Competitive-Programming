#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e7+7;
int n;
ll k;
int arr[N];
ll m;
bool ok(ll v)
{
    ll sum=0;
    for(ll i=n-1;i>=m;i--)
    {
        if(arr[i]<v)
            sum+=(v-arr[i]);
    }
    //cout<<sum<<" "<<k<<endl;
    return (sum<=k);
}
ll bs(ll l=0,ll r=10e9+10e9)
{
    while(l<r)
    {
        ll mid=l+((r-l)>>1)+1;
        //cout<<l<<" "<<r<<" "<<mid<<" "<<ok[mid]<<endl;
        if(ok(mid))
        {
            //cout<<"ok"<<endl;
            l=mid;
        }
        else
            r=mid-1;
    }
    return l;
}

int main ()
{
    cin>>n>>k;
    for(int i=0;i<n;i++) scanf("%d",arr+i);
    sort(arr,arr+n);
    m=n/2;
    cout<<bs()<<endl;


    return 0;
}
