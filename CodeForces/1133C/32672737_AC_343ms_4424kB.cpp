#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int m=1;
    for(int i=0;i<n-1;i++)
    {
        int idx=upper_bound(arr,arr+n,arr[i]+5)-arr-i;
        if(idx>m)
            m=idx;
    }
    cout<<m<<endl;
    return 0;
}
