#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7,N=1e6+5;
int fail[N];
void KMP (string s)
{
    for(int i=1;i<s.size();i++)
    {
        int j=fail[i-1];
        while(j>0&&s[j]!=s[i])
            j=fail[j-1];
        if(s[j]==s[i])
            fail[i]=j+1;
        else
            fail[i]=0;
    }
}
int main()
{
    int tc;
    cin>>tc;
    string s;
    int n;
    while(tc--)
    {
        memset(fail,0,sizeof fail);
        cin>>s;
        KMP(s);
        bool iszero=1;
        int cnt=0;
        bool isincer=1;
        bool ok=1;
        int idx=0;
        if(fail[s.size()-1] && fail[s.size()-1]%(s.size()-fail[s.size()-1])==0)
        {
            cout<<s.size()-fail[s.size()-1]<<endl;
        }
        else
            cout<<s.size()<<endl;
        if(tc)
            cout<<endl;
    }
    return 0;
}


