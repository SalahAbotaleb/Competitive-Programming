#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7,N=1e5+5,b1=27,b2=31,sz=2;
int pw1[N],pw2[N],inv1[N],inv2[N],pref1[N][sz],pref2[N][sz];
int mul(int a,int b)
{
    return (1ll*a*b)%mod;
}
int add(int a,int b)
{
    return ((1ll)*a+b+mod)%mod;
}
int fp(int b,int p)
{
    int ans=1;
    while(p)
    {
        if(p&1)
            ans=mul(ans,b);
        b=mul(b,b);
        p>>=1;
    }
    return ans;
}
void pre()
{
    pw1[0]=pw2[0]=inv1[0]=inv2[0]=1;
    int mul_inv1=fp(b1,mod-2);
    int mul_inv2=fp(b2,mod-2);
    for(int i=1;i<N;i++)
    {
        pw1[i]=mul(pw1[i-1],b1);
        pw2[i]=mul(pw2[i-1],b2);
        inv1[i]=mul(inv1[i-1],mul_inv1);
        inv2[i]=mul(inv2[i-1],mul_inv2);
    }
}

void hashstr(string s,int k)
{
    for(int i=1;i<=s.size();i++)
    {
        int idx=s[i-1]-'a'+1;
        pref1[i][k]=add(pref1[i-1][k],mul(idx,pw1[i-1]));
        pref2[i][k]=add(pref2[i-1][k],mul(idx,pw2[i-1]));
    }
}
pair<int,int> gethash(int l,int r,int k)
{
   return {mul(add(pref1[r][k],-1*pref1[l-1][k]),inv1[l-1]),mul(add(pref2[r][k],-1*pref2[l-1][k]),inv2[l-1])};
}
int main()
{
    pre();
    string s;
    while(cin>>s)
    {
        string sr=s;
        reverse(sr.begin(),sr.end());
        hashstr(s,0);
        hashstr(sr,1);
        auto hash1= gethash(1,s.size(),0);
        auto hash2= gethash(1,s.size(),1);
        int len=s.size();
        string ans;
        for(int i=0;i<len;i++)
        {
            if(hash1==hash2)
            {
                break;
            }
            int idx=s[i]-'a'+1;
            auto hashf= gethash(1,i+1,0);
            auto hashr= gethash(len-i,len,1);
            pair<int,int>cmp1;
            pair<int,int>cmp2;
            cmp1.first=add(hash1.first,mul(hashr.first,pw1[s.size()]));
            cmp1.second=add(hash1.second,mul(hashr.second,pw2[s.size()]));
            cmp2.first=add(hashf.first,mul(hash2.first,pw1[i+1]));
            cmp2.second=add(hashf.second,mul(hash2.second,pw2[i+1]));
            ans+=s[i];
            if(cmp1==cmp2)
            {
                break;
            }
        }
        reverse(ans.begin(),ans.end());
        cout<<s+ans<<endl;
    }
    return 0;
}


