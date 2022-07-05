#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int c=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n-2;i++)
        for(int j=i+1;j<n-1;j++)
            for(int k=j+1;k<n;k++)
                    {   //cout<<i<<" "<<j<<" "<<k<<endl;
                        if(arr[i]!=arr[j]&&arr[i]!=arr[k]&&arr[j]!=arr[k]&&arr[i]+arr[j]>arr[k]&&arr[j]+arr[k]>arr[i]&&arr[i]+arr[k]>arr[j])
                        {
                            //cout<<i<<" "<<j<<" "<<k<<endl;
                            c++;
                        }
                    }
    cout<<c<<endl;

    return 0;
}
