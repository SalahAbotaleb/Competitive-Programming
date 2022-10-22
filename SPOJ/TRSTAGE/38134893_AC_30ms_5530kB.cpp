#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
const int sz=1e6;
double dp[256][32];
int n,m,p,a,q;
using namespace std;
vector<vector< pair <int,int> >>adj;
int num[8];
double solve(int msk,int pidx)
{
    if(pidx==q)
        return 0;
    if(dp[msk][pidx]!=-1) return dp[msk][pidx];
    double res=INT_MAX;
    for(auto it:adj[pidx])
        for(int i=0;i<n;i++)
        {
            if(msk&(1<<i))
                continue;
            res=min(res,(double)it.second/num[i]+solve(msk|(1<<i),it.first));
        }
    return dp[msk][pidx]=res;
}
int main()
{
    while(cin>>n>>m>>p>>a>>q,n)
    {
        for(int i=0;i<256;i++)
            for(int j=0;j<32;j++)
                dp[i][j]=-1;
        adj.clear();
        adj.resize(m);
        q--;
        a--;
        for(int i=0;i<n;i++) cin>>num[i];
        for(int i=0;i<p;i++)
        {
            int u,v,c;
            cin>>u>>v>>c;
            u--,v--;
            adj[u].push_back({v,c});
            adj[v].push_back({u,c});
        }
        double ans=solve(0,a);
        if(ans!=INT_MAX)
        cout<<fixed<<setprecision(3)<<ans<<endl;
        else
            cout<<"Impossible\n";
    }
    return 0;
}


