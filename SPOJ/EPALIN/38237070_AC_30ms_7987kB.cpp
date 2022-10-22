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
    string s;
    while(cin>>s)
    {
        memset(fail,0,sizeof fail);
        string rev=s;
        reverse(rev.begin(),rev.end());
        KMP(rev);
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            while(j>0&&s[i]!=rev[j])
                j=fail[j-1];
            if(s[i]==rev[j])
                j++;
        }
        string ad=s.substr(0,s.size()-j);
        reverse(ad.begin(),ad.end());
        cout<<s+ad<<endl;

    }
    return 0;
}


