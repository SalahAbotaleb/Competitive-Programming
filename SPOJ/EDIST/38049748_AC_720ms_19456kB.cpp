#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
using namespace std;
int dp[2000][2000];
string a,b;
int recursive_dp(int i,int j)
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
}
int main()
{

    int tc;
    cin>>tc;
    while(tc--)
    {
        memset(dp,-1,sizeof dp);
        cin>>a>>b;
        cout<<recursive_dp(0,0)<<endl;
    }
    return 0;
}


