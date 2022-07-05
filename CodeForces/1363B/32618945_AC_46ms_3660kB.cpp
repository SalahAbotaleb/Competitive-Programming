#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n;
    cin>>n;
    while(n--)
    {
    cin>>s;
    int pres0[s.size()+1]={ 0 };
    int pres1[s.size()+1]={ 0 };
    for(int i=0;i<s.size();i++)
    {
        pres0[i+1]=(s[i]=='0');
        pres1[i+1]=(s[i]=='1');
    }
    int e=s.size();
    for(int i=1;i<=e;i++)
    {
        pres0[i]+=pres0[i-1];
        pres1[i]+=pres1[i-1];
    }
   // cout<<pres0[e]<<" "<<pres1[e]<<endl;
    int res=min(pres0[s.size()],pres1[s.size()]);
    for(int i=1;i<=e;i++)
    {
        res=min(res,pres1[i]+pres0[e]-pres0[i]);
        res=min(res,pres0[i]+pres1[e]-pres1[i]);
    }
    cout<<res<<endl;
    }
    return 0;
}
