#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
using namespace std;
int dp[6000][6000];
string s;
int solve(int i,int j)
{
    if(i>j)
        return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j]) return dp[i][j]=solve(i+1,j-1);
    return dp[i][j]=min(1+solve(i+1,j),1+solve(i,j-1));
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--) {
        //memset(dp,-1,sizeof dp);
        cin>>s;
        vector<vector<int>>ds(s.size()+1,vector<int>(s.size()+1,1e7));
        //cout<<solve(0,s.size()-1)<<endl;
        ds[0][s.size()-1]=0;
        for(int i=0;i<s.size();i++)
            for(int j=s.size()-1;j>=0;j--)
            {
                if(s[i]==s[j] &&j) ds[i+1][j-1]=min(ds[i+1][j-1],ds[i][j]);
                ds[i+1][j]=min(ds[i+1][j],1+ds[i][j]);
                if(j)
                    ds[i][j-1]=min(ds[i][j-1],1+ds[i][j]);
            }
        int mn=1e9;
        for(int i=0;i<s.size();i++)
            for(int j=0;j<s.size();j++)
                if(i>j)
                    mn=min(ds[i][j],mn);
        cout<<mn<<endl;
    }
    return 0;
}
