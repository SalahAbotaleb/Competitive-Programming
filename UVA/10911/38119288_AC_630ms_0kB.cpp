#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
const int sz=1e6;
using namespace std;
int n;
int x[20];
int y[20];
double dp[70000][17];
double solve(int msk,int pidx)
{
    if(msk ==((1<<n)-1))
        return 0;
    double &ret=dp[msk][pidx];
    if(ret!=-1) return ret;
    if(ret==-1)
        ret=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        if((msk>>(i-1))&1)
            continue;
        double plus=(pidx?sqrt((x[pidx]-x[i])*(x[pidx]-x[i])+(y[pidx]-y[i])*(y[pidx]-y[i])):0);
        ret=min(ret,solve(msk|(1<<(i-1)),(pidx==0?i:0))+plus);
    }
    return ret;
}
int main()
{
    int cnt=0;
    while(cin>>n,n)
    {
        for(int i=0;i<70000;i++)
            for(int j=0;j<17;j++)
                dp[i][j]=-1;

        n=n*2;
        string s;
        for (int i = 1; i <=n ; ++i) {
            cin>>s>>x[i]>>y[i];
        }
        cout<<"Case "<<++cnt<<": ";
        cout<<fixed<<setprecision(2)<<solve(0,0)<<endl;
    }
    return 0;
}


