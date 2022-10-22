#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7,N=1e6+5;
int dp[101][101][101];
string a,b,v;
vector<int>fails;
vector<int> prefix_function (string s)
{
    vector<int>fail(s.size(),0);
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
    return fail;
}
vector<int> KMP(string s,string pat)
{
    vector<int>fail= prefix_function(pat);
    vector<int>ans;
    int j=0;
    for(int i=0;i<s.size();i++)
    {
        while(j>0&&s[i]!=pat[j])
            j=fail[j-1];
        if(s[i]==pat[j])
            j++;
        if(j==pat.size())
        {
            ans.push_back(i-j+1);
            j=fail[j-1];
        }
    }
    return ans;
}
int solve(int i,int j,int mtch)
{
    if(i>=a.size() || j>=b.size())
        return 0;
    if(dp[i][j][mtch]!=-1) return dp[i][j][mtch];
    if(a[i]==b[j])
    {
        int tmp=mtch;
        int opta=solve(i+1,j+1,mtch),optb=0;
        while(tmp>0&&a[i]!=v[tmp]) {
            tmp=fails[tmp-1];
        }
        if(a[i]==v[tmp]) {
            tmp++;
        }
        if(tmp!=v.size())
        {
            optb=1+solve(i+1,j+1,tmp);
        }
        return dp[i][j][mtch]=max(opta,optb);
    }
    int opt1=solve(i,j+1,mtch);
    int opt2=solve(i+1,j,mtch);
    return dp[i][j][mtch]=max({opt1,opt2});
}
void build(int i,int j,int mtch)
{
    if(i>=a.size() || j>=b.size())
        return;
    int ans=solve(i,j,mtch);
    if(a[i]==b[j])
    {
        int tmp=mtch;
        int opta=solve(i+1,j+1,mtch),optb=0;
        while(tmp>0&&a[i]!=v[tmp]) {
            tmp=fails[tmp-1];
        }
        if(a[i]==v[tmp]) {
            tmp++;
        }
        if(tmp!=v.size())
        {
            optb=1+solve(i+1,j+1,tmp);
        }
        if(ans==optb&&tmp!=v.size())
        {
            cout<<a[i];
            build(i+1,j+1,tmp);
        }
        else
        {
            build(i+1,j+1,mtch);
        }
        return;
    }
    int opt1=solve(i,j+1,mtch);
    int opt2=solve(i+1,j,mtch);
    if(ans==opt1)
    {
        build(i,j+1,mtch);
    }else
    {
        build(i+1,j,mtch);
    }
}
int main()
{
    memset(dp,-1,sizeof dp);
    cin>>a>>b>>v;
    fails= prefix_function(v);
    if(!solve(0,0,0))
    {
        cout<<0<<endl;
    }else
    {
        build(0,0,0);
    }
    return 0;
}


