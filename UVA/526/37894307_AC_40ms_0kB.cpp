#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
using namespace std;
int solve(int i,int j,string &a,string &b,vector<vector<int>>&dp)
{
    if(i==a.size()&&j==b.size())
        return 0;
    if(i==a.size())
        return b.size()-j;
    if(j==b.size())
        return a.size()-i;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j])
    {
        return dp[i][j]=solve(i+1,j+1,a,b,dp);
    }
    int opt1=1+solve(i+1,j,a,b,dp); //delete
    int opt2=1+solve(i+1,j+1,a,b,dp); //replace
    int opt3=1+solve(i,j+1,a,b,dp); //insert
    return dp[i][j]=min({opt1,opt2,opt3});
}
void build(int i,int j,int ri,int &cnt,string &a,string &b,vector<vector<int>>&dp)
{
    if(i==a.size()&&j==b.size())
        return;
    if(i==a.size())
    {
            for(int k=j;k<b.size();k++)
            {
                cout<<++cnt<<" Insert "<<ri+1<<","<<b[k]<<endl;
                ri++;
            }
        return;
    }
    if(j==b.size())
    {
            for(int k=i;k<a.size();k++)
            {
                cout<<++cnt<<" Delete "<<ri+1<<endl;
            }
            return;
    }
    if(a[i]==b[j])
    {
        build(i+1,j+1,ri+1,cnt,a,b,dp);
        return;
    }

    int opt1=1+solve(i+1,j,a,b,dp); //delete
    int opt2=1+solve(i+1,j+1,a,b,dp); //replace
    int opt3=1+solve(i,j+1,a,b,dp); //insert
    if(opt1<=opt2&&opt1<=opt3)
    {
        cout<<++cnt<<" Delete "<<ri+1<<endl;
        build(i+1,j,ri,cnt,a,b,dp);
    }else
    {
        if(opt2<opt3&&opt2<opt1)
        {
            cout<<++cnt<<" Replace "<<ri+1<<","<<b[j]<<endl;
            build(i+1,j+1,ri+1,cnt,a,b,dp);
        }
        else
        {
            cout<<++cnt<<" Insert "<<ri+1<<","<<b[j]<<endl;
            build(i,j+1,ri+1,cnt,a,b,dp);
        }
    }
}
int main()
{
    int n;
    string a,b;
    int cc=0;
    while(getline(cin,a)&&getline(cin,b)) {
        vector<vector<int>>dp(81,vector<int>(81,-1));
        if(cc!=0)
        {
            cout<<endl;
            cc++;
        }

        cout<<solve(0,0,a,b,dp)<<endl;
        int cnt=0;
        build(0,0,0,cnt,a,b,dp);
    }return 0;
}


