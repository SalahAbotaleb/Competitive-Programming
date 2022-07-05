#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    ll t;
    cin>>n>>t;
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",arr+i);
    int l=0,r=0;
    ll sum=0;
    int ans=0;
    while(l<n)
    {
        while(r<n&&sum+arr[r]<=t)
        {
            //cout<<sum<<endl;
            sum+=arr[r];
            //cout<<l<<" "<<r<<endl;
            ans=max(ans,r-l+1);
            r++;
        }
        sum-=arr[l];
        l++;
    }
    cout<<ans<<endl;


    return 0;
}
