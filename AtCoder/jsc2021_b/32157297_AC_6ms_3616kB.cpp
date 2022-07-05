#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int,int>mp;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n+m;i++)
    {
         int x;cin>>x;mp[x]++;
    }

    for(auto it=mp.begin();it!=mp.end();it++)
    {
        if(it->second==1)
        {
            cout<<it->first<<" ";
        }
    }
    cout<<endl;
    return 0;

}
