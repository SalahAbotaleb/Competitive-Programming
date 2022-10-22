#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
using namespace std;
string a,b;
/*int recursive_dp(int i,int j)
{
    if(i==a.size()&&j!=b.size())
        return b.size()-j;
    if(i!=a.size()&&j==b.size())
        return a.size()-i;
    if(i==a.size()&&j==b.size())
        return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j])
    {
        return dp[i][j]=recursive_dp(i+1,j+1);
    }
    int opt1=1+ recursive_dp(i+1,j+1);
    int opt2=1+ recursive_dp(i+1,j);
    int opt3=1+ recursive_dp(i,j+1);
    return dp[i][j]=min({opt1,opt2,opt3});
}*/
int main()
{

    int tc;
    cin>>tc;
    while(tc--)
    {
        cin>>a>>b;
        //cout<<recursive_dp(0,0)<<endl;
        int k=max(a.size(),b.size());
        vector<vector<int>>dp(k+1,vector<int>(k+1,1e7));
        dp[0][0]=0;
        for(int i=0;i<k;i++)
            for(int j=0;j<k;j++)
            {
                if(i>=k || j>=k)
                {
                    dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+1);
                    continue;
                }
                if(a[i]==b[j]) dp[i+1][j+1]=min(dp[i][j],dp[i+1][j+1]);
                else
                {
                    dp[i+1][j+1]=min(1+dp[i][j],dp[i+1][j+1]);
                    dp[i+1][j]=min(1+dp[i][j],dp[i+1][j]);
                    dp[i][j+1]=min(1+dp[i][j],dp[i][j+1]);
                }
            }
        cout<<dp[k][k]<<endl;
    }
    return 0;
}


