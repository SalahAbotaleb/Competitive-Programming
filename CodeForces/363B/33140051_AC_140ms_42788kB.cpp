#include <bits/stdc++.h>
using namespace std;
const int N=1e7+7;
int arr[N];
int n,k;
int main()
{
    cin>>n>>k;
    int mval=INT_MAX;
    int idx;
    cin>>arr[0];
    for(int i=1;i<n;i++)
    {
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }
   /*for(int i=0;i<n;i++)
        cout<<arr[i]<<" \n"[i==n-1];*/
    for(int i=0;i<=n-k;i++)
    {
        if(i==0)
        {
            if(arr[i+k-1]<mval)
            {
                mval=arr[i+k-1];
                idx=i;
            }
            continue;
        }
        if(arr[i+k-1]-arr[i-1]<mval)
        {
            mval=arr[i+k-1]-arr[i-1];
            idx=i;
        }
    }
    cout<<idx+1<<endl;
    return 0;
}
