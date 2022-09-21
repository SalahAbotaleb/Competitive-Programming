#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>v={1,5,10,25,50};
ll solve(int rw,int idx,vector<vector<ll>>&dp)
{
    if(rw==0)
        return 1;
    if(idx==5)
        return 0;
    if(dp[rw][idx]!=-1) return dp[rw][idx];
    ll opt1=(rw-v[idx]>=0)?solve(rw-v[idx],idx,dp):0; //take
    ll opt2=solve(rw,idx+1,dp); //leave
    return dp[rw][idx]=opt1+opt2;
}
int main()
{
    int n;
    vector<vector<ll>>dp(30001,vector<ll>(5,-1));
    while(cin>>n) {
       ll ans=solve(n,0,dp);
        if(ans!=1)
        cout<<"There are "<<ans<<" ways to produce "<<n<<" cents change.\n";
       else
        cout<<"There is only 1 way to produce "<<n<<" cents change.\n";
    }
    return 0;
}


