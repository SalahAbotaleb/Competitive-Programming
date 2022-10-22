#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
using namespace std;
int dp[4001];
int n;
int a,b,c;
int solve(int l)
{
    if(l==n)
        return 0;
    if(dp[l]!=-1) return dp[l];
    int opt1=0,opt2=0,opt3=0;
    if(l+a<=n) opt1=1+solve(l+a);
    if(l+b<=n) opt2=1+solve(l+b);
    if(l+c<=n) opt3=1+solve(l+c);
    if(opt1<=0&&opt2<=0&&opt3<=0)
        return dp[l]=INT_MIN;
    return dp[l]=max({opt1,opt2,opt3});
}
int main()
{
    memset(dp,-1,sizeof dp);
    cin>>n>>a>>b>>c;
    cout<<solve(0)<<endl;
    return 0;
}


