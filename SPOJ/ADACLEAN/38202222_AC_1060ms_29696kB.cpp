#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7,N=1e6+5,b1=27,b2=31;
int pw1[N],pw2[N],inv1[N],inv2[N],pref1[N][2],pref2[N][2];

int mul(int a,int b)
{
    return (1ll *(a%mod) * (b%mod))%mod;
}
int add(int a,int b)
{
    return ((1ll)*a+b+mod)%mod;
}
int fp(int b,int pow)
{
    int res=1;
    while(pow>0)
    {
        if(pow&1)
            res=mul(res,b);
        b=mul(b,b);
        pow>>=1;
    }
    return res;
}
void pre()
{
    pw1[0]=pw2[0]=inv1[0]=inv2[0]=1;
    int mul_inv1=fp(b1,mod-2);
    int mul_inv2=fp(b2,mod-2);
    for(int i=1;i<N;i++)
    {
        pw1[i]=mul(b1,pw1[i-1]);
        pw2[i]=mul(b2,pw2[i-1]);
        inv1[i]=mul(mul_inv1,inv1[i-1]);
        inv2[i]=mul(mul_inv2,inv2[i-1]);
    }
}
pair<int,int> hashstr(string s,int pos)
{
    int ans1=0;
    int ans2=0;
    for(int i=1;i<=s.size();i++)
    {
        int idx=s[i-1]-'a'+1;
        ans1=add(ans1,mul(idx,pw1[i-1]));
        ans2=add(ans2,mul(idx,pw2[i-1]));
        pref1[i][pos]=ans1;
        pref2[i][pos]=ans2;
    }
    return {ans1,ans2};
}
pair<int,int> hashsubstr(int i,int j,int pos)
{
    int ans1=mul(add(pref1[j][pos],-1*pref1[i-1][pos]),inv1[i-1]);
    int ans2=mul(add(pref2[j][pos],-1*pref2[i-1][pos]),inv2[i-1]);
    return {ans1,ans2};
}
int main()
{
    pre();
    int tc;
    cin>>tc;
    while(tc--)
    {
        string s;
        int n,k;
        cin>>n>>k;
        cin>>s;
        hashstr(s,0);
        int sz=n-k;
        set<pair<int,int>>st;
        for(int i=0;i<=sz;i++)
        {
            st.insert(hashsubstr(i+1,i+k,0));
        }
        cout<<st.size()<<endl;
    }

    return 0;
}


