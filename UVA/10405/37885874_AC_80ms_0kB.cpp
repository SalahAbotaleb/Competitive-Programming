#include <bits/stdc++.h>
#define ll long long
using namespace std;
int solve(int i,int j,string a,string b,vector<vector<int>>&dp)
{
    if(i==a.size() || j==b.size())
        return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j])
        return dp[i][j]=1+solve(i+1,j+1,a,b,dp);
    int opt1=solve(i+1,j,a,b,dp); //fix second
    int opt2=solve(i,j+1,a,b,dp); //fix first
    return dp[i][j]=max(opt1,opt2);
}
int main()
{
    string a,b;
    while(getline(cin,a)&&getline(cin,b))
    {
        vector<vector<int>>dp(a.size(),vector<int>(b.size(),-1));
        cout<<solve(0,0,a,b,dp)<<endl;
    }

    return 0;
}


