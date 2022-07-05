#include <bits/stdc++.h>
using namespace std;
long long calc(int arr[],int l,int r)
{
    long long res=1;
    for(int i=l;i<=r;i++)
    {
        res*=arr[i];
    }
    return res;
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) scanf("%d",arr+i);
        sort(arr,arr+n);
        vector <long long> v;
        v.push_back(calc(arr,n-5,n-1));
        v.push_back(calc(arr,0,4));
        v.push_back(calc(arr,0,1)*calc(arr,n-3,n-1));
        v.push_back(calc(arr,0,3)*calc(arr,n-1,n-1));
        /*cout<<calc(arr,n-5,n-1)<<endl;
        cout<<calc(arr,0,4)<<endl;
        cout<<calc(arr,0,1)*calc(arr,n-3,n-1)<<endl;
        cout<<calc(arr,0,3)*calc(arr,n-1,n-1)<<endl;*/
        cout<<*max_element(v.begin(),v.end())<<endl;
    }

        return 0;
    }


