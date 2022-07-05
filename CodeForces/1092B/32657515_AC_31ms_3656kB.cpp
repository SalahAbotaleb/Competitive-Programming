#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",arr+i);
    sort(arr,arr+n);
    int c=0;
    for(int i=1;i<n;i+=2)
    {
        c+=arr[i]-arr[i-1];
    }
    cout<<c<<endl;

    return 0;
}
