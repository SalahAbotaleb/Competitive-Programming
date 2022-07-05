#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",arr+i);
    sort(arr,arr+n,greater<int>());
    bool ok=0;
    for(int i=0;i<n-2;i++)
    {
        if(arr[i]<arr[i+1]+arr[i+2])
        {
            ok=1;
            break;
        }
    }
    if(ok)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
