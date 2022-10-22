#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
using namespace std;
ll solve(int val,int grplen,int n,int k,vector<vector<ll>>&dp)
{
    if(grplen==k)
        return 1;
    if(val>n)
        return 0;
    if(dp[grplen][val]!=-1) return dp[grplen][val];
    ll opt1=0;
    for(int i=val;i<=n;i+=val){
    opt1=(opt1%mod+solve(i,grplen+1,n,k,dp)%mod)%mod;
    }
    return dp[grplen][val]=opt1%mod;
}
int main()
{
    vector<vector<ll>>dp(2001,vector<ll>(2001,-1));
    int n,k;
    cin>>n>>k;
    cout<<solve(1,0,n,k,dp)<<endl;
    return 0;
}


