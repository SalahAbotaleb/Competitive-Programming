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
        memset(dp,-1,sizeof dp);
        cin>>s;
        cout<<solve(0,s.size()-1)<<endl;
    }


    return 0;
}


