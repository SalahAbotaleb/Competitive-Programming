#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
using namespace std;
int dp[10000005][4];
int n;
int recursive_dp(int idx,int curr)
{
    if(idx==n&&curr==0)
        return 1;
    if(idx==n)
        return 0;
    if(dp[idx][curr]!=-1) return dp[idx][curr];
    int ans=0;
    for(int i=0;i<4;i++)
        if(i!=curr)
            ans=(ans%mod+recursive_dp(idx+1,i)%mod)%mod;
    return dp[idx][curr]=ans;
}
int main()
{
    cin>>n;
    memset(dp,0,sizeof dp);
    dp[0][0]=1;

    for(int idx=1;idx<=n;idx++)
        for(int curr=0;curr<4;curr++)
        {
            int ans=0;
            for(int i=0;i<4;i++)
                if(curr!=i)
                    ans=(ans%mod+dp[idx-1][i]%mod)%mod;
            dp[idx][curr]=ans;
        }
    cout<<dp[n][0]<<endl;
    return 0;
}


