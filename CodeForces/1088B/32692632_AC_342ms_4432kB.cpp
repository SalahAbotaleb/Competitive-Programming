#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    int pre[n+1]={ 0 };
    for(int i=0;i<n;i++) scanf("%d",arr+i);
    sort(arr,arr+n);
    int sub=0;
    int l=0;
    for(int j=0;l<k && j<n;j++)
    {
        if(arr[j]-sub==0)
            {
                continue;
            }
        cout<<arr[j]-sub<<endl;
        sub+=arr[j]-sub;
        l++;
    }
    for(int i=0;i<k-l;i++)
        cout<<0<<endl;

    return 0;
}

