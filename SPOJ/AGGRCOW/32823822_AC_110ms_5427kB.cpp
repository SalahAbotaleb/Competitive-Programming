#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,c;
const int N=1e7;
int arr[N];
bool ok(ll num)
{
    int cc=1,found=0,element=1;
    for(int i=0;i<n&&i+cc<n;cc++)
    {
       // cout<<i<<"  "<<i+cc<<"  "<<arr[i+cc]-arr[i]<<endl;
        if(arr[i+cc]-arr[i]>=num)
        {
            //cout<<"yes"<<endl;
            /*if(arr[i+cc]-arr[i]==num)
                found=1;*/
            i=i+cc;
            cc=0;
            element++;
        }

    }
    if(element>=c)
        return 1;
    return 0;
}
int bs(ll l=0,ll r=1e9)
{
    ll mid;
    while(l<r)
    {
        mid=l+((r-l)>>1)+1;
        //cout<<mid<<endl;
        if(ok(mid))
            l=mid;
        else
            r=mid-1;
    }
    return l;
}
int main()
{

    int tc;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>c;
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n);
        cout<<bs()<<endl;
    }

    return 0;
}

