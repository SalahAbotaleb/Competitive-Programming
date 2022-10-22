#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
using namespace std;
ll solve(int idx,int pmethod,int n,vector<int>&x,vector<int>&h,vector<vector<ll>>&dp)
{
    if(idx==n)
        return 0;
    if(dp[idx][pmethod]!=-1) return dp[idx][pmethod];
    ll availr=(idx+1!=n)?x[idx+1]-x[idx]-1:loo;
    ll availl=(pmethod==2)?x[idx]-x[idx-1]-h[idx-1]-1:(idx==0)?loo:x[idx]-x[idx-1]-1;
    ll opt2=(availl>=h[idx])?1+solve(idx+1,1,n,x,h,dp):0; //pick left
    ll opt1=solve(idx+1,0,n,x,h,dp); //leave
    ll opt3=(availr>=h[idx])?1+solve(idx+1,2,n,x,h,dp):0; //pick right
    return dp[idx][pmethod]=max({opt1,opt2,opt3});
}
int main()
{
    vector<vector<ll>>dp(200005,vector<ll>(3,-1));
    int n;
    cin>>n;
    vector<int>x(n);
    vector<int>h(n);
    vector<pair<int,int>>input(n);
    for(int i=0;i<n;i++) cin>>input[i].first>>input[i].second;
    sort(input.begin(),input.end());
    for(int i=0;i<n;i++) x[i]=input[i].first,h[i]=input[i].second;
    cout<<solve(0,0,n,x,h,dp)<<endl;
    return 0;
}


