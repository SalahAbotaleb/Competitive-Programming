#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map <string,int> mp;
    vector <string> v(n);
    for(int i=0; i<n;i++)
    {
        string x;
        cin>>x;
        mp[x]=i;
        v[i]="0";
    }
    int i=0;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        v[it->second]=it->first;
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        if(v[i]!="0")
            cout<<v[i]<<endl;


    return 0;
}
