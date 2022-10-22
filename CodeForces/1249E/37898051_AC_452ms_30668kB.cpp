#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
using namespace std;
ll solve(int idx,int pmethod,int n,int c,vector<int>&s,vector<int>&e,vector<vector<ll>>&dp)
{
    if(idx==-1)
        return 0;
    if(dp[idx][pmethod]!=-1) return dp[idx][pmethod];
    ll opt1= s[idx]+solve(idx-1,0,n,c,s,e,dp);
    ll opt2= (pmethod!=1?c:0)+e[idx]+solve(idx-1,1,n,c,s,e,dp);
    return dp[idx][pmethod]=min(opt1,opt2);
}
void build(int idx,int pmethod,int n,int c,vector<int>&s,vector<int>&e,vector<vector<ll>>&dp)
{
    if(idx==-1)
        return;
    ll opt1= solve(idx,0,n,c,s,e,dp);
    ll opt2=loo;
    if(dp[idx][1]!=-1)
            opt2=solve(idx,1,n,c,s,e,dp);
    if(dp[idx][1]!=-1 && pmethod==0)
        opt2+=c;
    if(opt1<=opt2)
    {
        build(idx-1,0,n,c,s,e,dp);
        cout<<dp[idx][0]<<" ";
    }
    else
    {
        build(idx-1,1,n,c,s,e,dp);
        cout<<opt2<<" ";
    }
    return;
}
int main()
{
    vector<vector<ll>>dp(200005,vector<ll>(2,-1));
    int n,c;
    cin>>n>>c;
    vector<int>s(n-1);
    vector<int>e(n-1);
    for(int i=0;i<n-1;i++)
        cin>>s[i];
    for(int i=0;i<n-1;i++)
        cin>>e[i];
    solve(n-2,0,n-1,c,s,e,dp);
    cout<<0<<" ";
    build(n-2,0,n-1,c,s,e,dp);
    return 0;
}


