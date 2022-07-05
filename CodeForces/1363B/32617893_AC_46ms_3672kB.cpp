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
    int suf0,suf1,pre0,pre1;
    suf0=suf1=pre0=pre1=0;
    for(int i=s.size()-1;i>=0;i--)
    {
        suf0+=(s[i]=='0');
        suf1+=(s[i]=='1');
    }
    int res=min(suf0,suf1);
    for(int i=0;i<s.size();i++)
    {
        pre0+=(s[i]=='0');
        pre1+=(s[i]=='1');
        suf0-=(s[i]=='0');
        suf1-=(s[i]=='1');
        res=min(res,pre1+suf0);
        res=min(res,pre0+suf1);
    }
    cout<<res<<endl;
    }
    return 0;
}

