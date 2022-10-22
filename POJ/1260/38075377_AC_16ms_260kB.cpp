#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
using namespace std;
int dp[100][100];
int num[100];
int cost[100];
int acc[101];
int n;
int solve(int l,int r)
{
    if(l==r)
        return (num[l]+10)*cost[l];
    if(dp[l][r]!=-1) return dp[l][r];
    int mn=INT_MAX;
    for(int i=l;i<r;i++)
    {
        mn=min(min(mn,solve(l,i)+solve(i+1,r)),(acc[r+1]-acc[l]+10)*cost[r]);
    }
    return dp[l][r]=mn;
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        memset(dp,-1,sizeof dp);
        memset(acc,0,sizeof acc);
      cin>>n;
      for(int i=0;i<n;i++)
      {
          cin>>num[i]>>cost[i];
      }
      for(int i=1;i<=n;i++)
          acc[i]+=acc[i-1]+num[i-1];
        cout<<solve(0,n-1)<<endl;
    }
    return 0;
}


