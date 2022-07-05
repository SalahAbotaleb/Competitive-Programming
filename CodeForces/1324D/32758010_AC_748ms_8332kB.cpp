#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin>>n;
    ll a[n],b[n];
    int s1=0,s2=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    ll arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=a[i]-b[i];
    }
    sort(arr,arr+n);
    int l=0,r=n-1;
    ll c=0;
    while(l<r)
    {
        if(arr[l]+arr[r]<=0)
            l++;
        else
        {
            c+=r-l;
            r--;
        }
    }
    cout<<c<<endl;

    return 0;
}
