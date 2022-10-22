#include <bits/stdc++.h>
#define ll long long
using namespace std;
int solve(int i,int j,string& s,vector<vector<int>>&dp)
{
    if(i>j)
        return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j]) return dp[i][j]=solve(i+1,j-1,s,dp);
    int opt1=1+solve(i+1,j,s,dp);
    int opt2=1+solve(i,j-1,s,dp);
    return dp[i][j]=min(opt1,opt2);
}
void build(int i,int j,int ri,int rj,string& s,string& ans,vector<vector<int>>&dp)
{
    if(i>j)
        return ;
    if(s[i]==s[j])
    {
        ans[ri]=ans[rj]=s[i];
        build(i+1,j-1,ri+1,rj-1,s,ans,dp);
        return;
    }
    int opt1=solve(i+1,j,s,dp);
    int opt2=solve(i,j-1,s,dp);
    if(opt1>opt2)
    {
        ans[ri]=ans[rj]=s[j];
        build(i,j-1,ri+1,rj-1,s,ans,dp);

    }
    else
    {
        ans[ri]=ans[rj]=s[i];
        build(i+1,j,ri+1,rj-1,s,ans,dp);
    }
}
int main()
{
    string s;
    while(cin>>s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        int cnt=solve(0,s.size()-1,s,dp);
        string ans;
        for(int i=0;i<cnt+s.size();i++)
            ans+="*";
        build(0,s.size()-1,0,cnt+s.size()-1,s,ans,dp);
        cout<<cnt<<" "<<ans<<endl;
    }
    return 0;
}


