#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,l,t;
    cin>>n>>l>>t;
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",arr+i);
    int diff[n-1];
    for(int i=0;i<n-1;i++) diff[i]=arr[i+1]-arr[i]-1;
    sort(diff,diff+n-1,cmp);
    int siz=accumulate(diff,diff+t-1,0);
    //cout<<siz<<endl;
    cout<<arr[n-1]-siz+1-arr[0];
    return 0;
}
