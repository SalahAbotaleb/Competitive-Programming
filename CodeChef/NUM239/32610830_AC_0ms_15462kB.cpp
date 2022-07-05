#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[100001] ={ 0 };
    for(int i=0;i<=100001;i++)
    {
        if(i%10==2 || i%10==3 || i%10==9 )
            {
                arr[i]=1;
            }
    }
    for(int i=1;i<=100001;i++) arr[i]+=arr[i-1];
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        cout<<arr[b]-arr[a-1]<<endl;
    }
    return 0;
}
