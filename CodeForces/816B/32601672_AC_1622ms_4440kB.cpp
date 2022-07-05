#include <bits/stdc++.h>
using namespace std;
vector <int> v (200002);
int main()
{
    int k,n,q;

    cin>>n>>k>>q;
    for(int i=0;i<n;i++)
    {
        int l;
        int r;
        cin>>l>>r;
        v[l]+=1;
        v[r+1]-=1;
    }
    for(int i=1;i<=200000;i++) v[i]+=v[i-1];
    for(int i=1;i<=200000;i++)
    {
        if(v[i]>=k)
        {
         v[i]=1;
        }else
            v[i]=0;
    }
    for(int i=1;i<=200000;i++) v[i]+=v[i-1];
    //for(int i=1;i<200;i++) cout<<v[i]<<" ";
    //cout<<endl;
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<v[r]-v[l-1]<<endl;
    }

    return 0;
}
