#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
using namespace std;
int dp[11][11];
int v[11];
int n;
int solve(int pidx,int idx)
{
    if(idx==n+1)
        return 0;
    if(dp[pidx][idx]!=-1) return dp[pidx][idx];
    int opt1=0,opt2=0;
    if(v[pidx]<v[idx]) opt1=1+solve(idx,idx+1);
    opt2=solve(pidx,idx+1);
    return dp[pidx][idx]=max(opt1,opt2);
}
int main()
{
    memset(dp,-1,sizeof dp);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>v[i];
    cout<<solve(0,1)<<endl;
    return 0;
}


