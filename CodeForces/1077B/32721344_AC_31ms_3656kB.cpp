#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr[i]=x;
    }
    int c=0;
    for(int i=1;i<n-1;i++)
    {
        if(arr[i]==0&&arr[i+1]==1&&arr[i-1]==1)
        {
            c++;
            arr[i+1]=0;
        }
    }
    cout<<c<<endl;
    return 0;
}
