#include <bits/stdc++.h>
using namespace std;
int main()
{
    map <string,int> mp;
     map <int,string>res;
    int n;
    cin>>n;
    for(int i=n;i>0;i--)
    {
        string tmp;
        cin>>tmp;
        mp[tmp]=i;
    }
    string arr[mp.size()];
    for(auto it=mp.begin();it!=mp.end();it++)
        {
            res[it->second]=it->first;
        }
   for(auto it=res.begin();it!=res.end();it++)
        {
            cout<<it->second<<endl;
        }



    return 0;
}
