#include <bits/stdc++.h>
#define ll long long
using namespace std;
int vals[]={1,5,10,25,50};
ll solve(int pidx,int idx,int n,vector<vector<ll>>&dp,vector<int>&v)
{
    if(idx==n)
        return 0;
    if(dp[pidx][idx]!=-1) return dp[pidx][idx];
    ll opt1=(v[idx]>v[pidx])? 1+solve(idx,idx+1,n,dp,v):0; //pick
    ll opt2=solve(pidx,idx+1,n,dp,v); //leave
    return dp[pidx][idx]=max(opt1,opt2);
}
int main()
{
    int n;
    cin>>n;
    vector<vector<ll>>dp(n+1,vector<ll>(n+1,-1));
    vector<int>v(n+1);
    v[0]=-1;
    for(int i=1;i<=n;i++) cin>>v[i];
    cout<<solve(0,1,n+1,dp,v)<<endl;

    return 0;
}


