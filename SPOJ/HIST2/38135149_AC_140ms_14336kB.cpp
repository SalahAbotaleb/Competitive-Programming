#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
const int sz=1e6;
vector<vector<pair<int,int>>>dp;
int h[16];
int n;
pair<int,int> solve(int msk,int pidx)
{
    if(msk == ((1<<n)-1))
        return {h[pidx],1};
    if(dp[msk][pidx].first!=-1) return dp[msk][pidx];
    pair<int,int> res={INT_MIN,0};
    int cc=0;
    for(int i=1;i<=n;i++)
    {
        if((1<<(i-1))&msk)
            continue;
        pair<int,int>ans=solve(msk|(1<<(i-1)),i);
        ans.first+=abs(h[pidx]-h[i])+2;
        if(ans.first>res.first)
            res=ans;
        else
            if(ans.first==res.first)
                res.second+=ans.second;
    }
    return dp[msk][pidx]=res;
}
int main()
{
    while(cin>>n,n) {
        for (int i = 1; i <= n; i++)
            cin >> h[i];
        h[0] = 0;
        dp=vector<vector<pair<int,int>>>((1<<n),vector<pair<int,int>>(n+1,{-1,0}));
        pair<int,int> ans = solve(0, 0);
        cout << ans.first<<" "<<ans.second << endl;
    }
    return 0;
}


