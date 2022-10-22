#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
using namespace std;
ll solve(int idx,int weight,int state,int d,int k,int n,vector<vector<vector<int>>>&dp)
{
    if(weight==n&&state==1)
        return 1;
    if(weight>n)
        return 0;
    if(dp[idx][weight][state]!=-1) return dp[idx][weight][state];
    ll ans=0;
    for(int i=1;i<=k;i++) {
        ans = (solve(i, weight + i, (i>=d)?1:state, d,k, n, dp) % mod + ans % mod) % mod;
    }
    return dp[idx][weight][state]=ans;
}
int main()
{
    vector<vector<vector<int>>>dp(101,vector<vector<int>>(101,vector<int>(2,-1)));
    int n,k,d;
    cin>>n>>k>>d;
    cout<<solve(1,0,0,d,k,n,dp)<<endl;
    return 0;
}


