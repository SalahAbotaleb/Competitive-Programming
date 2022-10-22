#include <bits/stdc++.h>
#define ll long long
using namespace std;
int vals[]={1,5,10,25,50};
ll solve(int rc,int idx,vector<vector<ll>>&dp)
{
    if(rc==0)
        return 1;
    if(dp[idx][rc]!=-1) return dp[idx][rc];
    int ans=0;
    for(int i=idx;i<5;i++)
    {
        if(rc-vals[i]>=0)
            ans+=solve(rc-vals[i],i,dp);
    }
    return dp[idx][rc]=ans;
}
int main()
{

    vector<vector<ll>>dp(5,vector<ll>(10000,-1));
    int n;
    while(cin>>n)
    {
        cout<<solve(n,0,dp)<<endl;
    }
    return 0;
}


