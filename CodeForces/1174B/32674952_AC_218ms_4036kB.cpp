#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int odd=0,even=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        odd+=(arr[i]%2);
        even+=1-(arr[i]%2);
    }
    if(even&&odd)
    {
      sort(arr,arr+n);
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" \n"[i==n-1];

    return 0;
}
