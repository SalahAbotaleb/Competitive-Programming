#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7,N=1e6+5,b1=27,b2=31,sz=4;
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
int solve(string a,string b,string c)
{
    string tmp;
    hashstr(a,0);
    hashstr(b,1);
    bool ok=0;
    for(int i=0;i<a.size();i++)
    {
        int len=min(a.size()-i,b.size());
        auto hash1= gethash(i+1,i+len,0);
        auto hash2=gethash(1,len,1);
        if(hash1==hash2)
        {
            ok=1;
            if(len==a.size()-i)
            {
                tmp+=b;
            }
            else
            {
                tmp=a;
            }
            break;
        }
        else
            tmp+=a[i];
    }
    if(!ok) tmp+=b;
    a=tmp;
    b=c;
    hashstr(a,0);
    hashstr(b,1);
    tmp="";
    ok=0;
    for(int i=0;i<a.size();i++)
    {
        int len=min(a.size()-i,b.size());
        auto hash1= gethash(i+1,i+len,0);
        auto hash2=gethash(1,len,1);
        if(hash1==hash2)
        {
            ok=1;
            if(len==a.size()-i)
            {
                tmp+=b;
            }
            else
            {
                tmp=a;
            }
            break;
        }
        else
            tmp+=a[i];
    }
    if(!ok) tmp+=b;
    return tmp.size();
}
int main()
{
    pre();
    string s[3];
    cin>>s[0]>>s[1]>>s[2];
    vector<int>v={0,1,2};
    int mn=INT_MAX;
    do{
        mn=min(mn,solve(s[v[0]],s[v[1]],s[v[2]]));
    }while(next_permutation(v.begin(),v.end()));
    cout<<mn<<endl;
    return 0;
}


