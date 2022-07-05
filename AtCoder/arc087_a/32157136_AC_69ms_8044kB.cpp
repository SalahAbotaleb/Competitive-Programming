#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int,int>mp;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
         int x;cin>>x;mp[x]++;
    }
    int c=0;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        if(it->first!=it->second)
        {
            if(it->first>it->second)
                c+=it->second;
            else
                c+=it->second-it->first;
        }
    }
    cout<<c<<endl;
    return 0;
}
