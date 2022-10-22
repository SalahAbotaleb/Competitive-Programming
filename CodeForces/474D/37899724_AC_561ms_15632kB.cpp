#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
using namespace std;
ll solve(int idx,int k,vector<ll>&dp)
{
    if(idx==0)
        return 1;
    if(dp[idx]!=-1) return dp[idx];
    ll opt1=(idx-k>=0)?solve(idx-k,k,dp):0;
    ll opt2=solve(idx-1,k,dp);
    return dp[idx]=(opt1%mod+opt2%mod)%mod;
}
int main()
{
    vector<ll>dp(200005,-1);
    int n,k;
    cin>>n>>k;
    solve(200004,k,dp);
    vector<ll>ans(200005,0);
    for(int i=1;i<=200000;i++)
        ans[i]=(dp[i]%mod+ans[i-1]%mod)%mod;
    while(n--)
    {
        int u,v;
        cin>>u>>v;
        cout<<(ans[v]-ans[u-1]+mod)%mod<<endl;
    }
    return 0;
}


