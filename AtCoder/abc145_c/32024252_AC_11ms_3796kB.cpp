#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n][2];
    int com[n];
    for(int i=0;i<n;i++)
    {
        com[i]=i;
        cin>>arr[i][1]>>arr[i][2];
    }
    double s=0;
    double c=0;
    do
    {
        //cout<<com[0]<<" "<<com[1]<<" "<<com[2]<<endl;
        for(int i=0;i<n-1;i++)
            {
                int idx=com[i];
                int nxt=com[i+1];
                s+=sqrt(pow(arr[idx][1]-arr[nxt][1],2)+pow(arr[idx][2]-arr[nxt][2],2));
                //cout<<sqrt(pow(arr[idx][1]-arr[][1],2)+pow(arr[idx][2]-arr[idx+1][2],2))<<endl;
            }
        c++;

    }while(next_permutation(com,com+n));
    //cout<<c<<endl;
    //cout<<s<<endl;
    cout<<fixed<<setprecision(10)<<s/c<<endl;

    return 0;
}
