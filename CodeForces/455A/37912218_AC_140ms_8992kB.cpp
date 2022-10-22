#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
using namespace std;
ll solve(int idx,int n,vector<int>&v,vector<ll>&dp)
{
  if(idx==n)
      return 0;
  if(dp[idx]!=-1) return dp[idx];
  ll cnt= upper_bound(v.begin(),v.end(),v[idx])-v.begin()-idx;
  ll nxt=lower_bound(v.begin(),v.end(),v[idx]+2)-v.begin();
  ll opt1=1ll*cnt*v[idx]+solve(nxt,n,v,dp); //take
  ll opt2=solve(idx+1,n,v,dp); //leave
  return dp[idx]=max(opt1,opt2);
}
int main()
{
    int n;
    cin>>n;
    vector<ll>dp(100001,-1);
    vector<int>v(n,-1);
    for(auto &it:v) cin>>it;
    sort(v.begin(),v.end());
    cout<<solve(0,n,v,dp)<<endl;
    return 0;
}


