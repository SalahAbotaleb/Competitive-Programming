#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool isok(int arr[], int idx,int n)
{
    bool ok=1;
    int i=idx-1;
            if(idx!=1&&idx!=n)
            {
                if(idx%2==1)
                {
                    if(arr[i]>arr[i-1]||arr[i]>arr[i+1])
                    {
                        ok=0;
                    }

                }else
                {
                    if(arr[i]<arr[i-1]||arr[i]<arr[i+1])
                    {
                        ok=0;
                    }
                }

            }
            if(idx==1)
            {
                if(arr[i]>arr[i+1])
                {
                    ok=0;
                }
            }
            if(idx==n)
                {
                if(idx%2==1)
                {
                    if(arr[i]>arr[i-1])
                    {
                        ok=0;
                    }
                }
                else
                {
                    if(arr[i]<arr[i-1])
                    {
                        ok=0;
                    }
                }

        }
        //cout<<"ok  "<<ok<<endl;
        return ok;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int arr2[]={1, 2, 1, 2};
    for(int i=0;i<n;i++) cin>>arr[i];
    //sort(arr,arr+n);
    /*for(int i=0;i<n;i++) cout<<arr[i]<<" \n"[i==n-1];
    cout<<"-----"<<endl;*/
    int idx=1;
    for(int i=0;i<n;i++)
    {
        if(isok(arr,idx,n)==0)
            swap(arr[i],arr[i+1]);
        idx++;
    }
    //cout<<"....."<<endl;
    int check=1;
    //for(int i=0;i<n;i++) cout<<arr[i]<<" \n"[i==n-1];
    idx=1;
    for(int i=0;i<n;i++)
    {
        if(isok(arr,idx,n)==0)
            {
                //cout<<i<<endl;
                check=0;
                break;
            }
        idx++;
    }
    if(check)
     for(int i=0;i<n;i++) cout<<arr[i]<<" \n"[i==n-1];
    else
        cout<<"Impossible"<<endl;
    return 0;
}
