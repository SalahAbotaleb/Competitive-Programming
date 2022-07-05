#include <bits/stdc++.h>
using namespace std;
int comp(string s,string sub,int n)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=sub[i])
        {
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
    string s;
    cin>>s;
    int sz=s.size();
    int mval=INT_MAX;
    for(int i=0;i<sz;i++)
    {
        string sub1=string(i,'1')+string(sz-i,'0');
        string sub2=string(i,'0')+string(sz-i,'1');
        //cout<<sub1<<"  "<<sub2<<endl;
        //cout<<comp(s,sub1,sz)<<"  "<<comp(s,sub2,sz)<<endl;
        mval=min({comp(s,sub1,sz),comp(s,sub2,sz),mval});
    }
    cout<<mval<<endl;
    }
    return 0;
}

