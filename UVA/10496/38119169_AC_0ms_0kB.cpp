#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
const int sz=1e6;
using namespace std;
int n;
int x[20];
int y[20];
int dp[1024][11];
int solve(int msk,int pidx)
{
    if(msk==(1<<n)-1)
        return abs(x[pidx]-x[0])+abs(y[pidx]-y[0]);
    int ret=INT_MAX;
    if(dp[msk][pidx]!=-1) return dp[msk][pidx];
    for(int i=1;i<=n;i++)
    {
        if((msk>>(i-1))&1)
            continue;
        ret=min(ret,solve(msk|(1<<(i-1)),i)+abs(x[pidx]-x[i])+abs(y[pidx]-y[i]));
    }
    return dp[msk][pidx]=ret;
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        memset(dp,-1,sizeof dp);
        cin>>x[0]>>y[0];
        cin>>x[0]>>y[0];
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>x[i]>>y[i];
        cout<<"The shortest path has length "<<solve(0,0)<<endl;
    }
    return 0;
}


