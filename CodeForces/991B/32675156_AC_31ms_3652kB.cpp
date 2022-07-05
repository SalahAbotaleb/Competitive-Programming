#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,s;
    s=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        s+=arr[i];
    }
    double avg=(double)s/n;
    int sum=ceil(n*4.5);
    //cout<<sum<<endl;
    int c=0;
    sort(arr,arr+n);
    for(int i=0;i<n && s<sum;i++)
    {
        c++;
        s+=5-arr[i];
        //cout<<s<<endl;
    }
    cout<<c<<endl;
    return 0;
}
