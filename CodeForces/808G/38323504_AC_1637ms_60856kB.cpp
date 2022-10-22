#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7,N=1e6+5;
vector<vector<int>>dp;
vector<vector<int>>mem;
string s,pat;
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
int helper(int j,char k)
{
    if(mem[j][k-'a']!=-1) return mem[j][k-'a'];
    int tmp=j;
    while(tmp>0&&k!=pat[tmp])
        tmp=fails[tmp-1];
    if(k==pat[tmp])
        tmp++;
    return mem[j][k-'a']=tmp;
}
int solve(int i,int mtch)
{
    if(i==s.size())
        return 0;
    if(dp[i][mtch]!=-1) return dp[i][mtch];
    if(s[i]!='?')
    {
        int tmp=helper(mtch,s[i]);
        if(tmp==pat.size())
            return dp[i][mtch]=1+solve(i+1,fails[tmp-1]);
        return dp[i][mtch]=solve(i+1,tmp);
    }
    int ans=0;
    for(char idx='a';idx<='z';idx++)
    {
        int tmp=helper(mtch,idx);
        int aa=0;
        if(tmp==pat.size())
            aa=1+solve(i+1,fails[tmp-1]);
        else
            aa=solve(i+1,tmp);
        ans=max(ans,aa);
    }
    return dp[i][mtch]=ans;
}
int main()
{
    cin>>s>>pat;
    fails= prefix_function(pat);
    dp=vector<vector<int>>(s.size(),vector<int>(pat.size(),-1));
    mem=vector<vector<int>>(s.size(),vector<int>(27,-1));
    cout<<solve(0,0)<<endl;
    return 0;
}


