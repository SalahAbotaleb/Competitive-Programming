#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#define ll long long
using namespace std;
int solve(int i,int j,string &a,string &b,vector<vector<int>>&dp)
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
void build(int i,int j,string &a,string &b,vector<vector<int>>&dp)
{
    if(i==a.size() || j==b.size())
        return;
    if(a[i]==b[j]) {
        cout << a[i];
        build(i+1,j+1,a,b,dp);
    }
    else
    {
        //if(dp[i][j+1]>dp[i+1][j])
        if(solve(i,j+1,a,b,dp)>solve(i+1,j,a,b,dp))
        {
            build(i,j+1,a,b,dp);
        }
        else
        {
            build(i+1,j,a,b,dp);
        }

    }

}
int main()
{
    string a,b;
    cin>>a>>b;
    vector<vector<int>>dp(a.size(),vector<int>(b.size(),-1));
    build(0,0,a,b,dp);

    return 0;
}


