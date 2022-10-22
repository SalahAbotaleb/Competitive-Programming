#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
using namespace std;
int dp[51][1001];
int main()
{

    int tc;
    cin>>tc;
    while(tc--) {
        memset(dp, 0, sizeof dp);
        int n, k;
        cin >> k >> n;
        vector<int> w(n+1); //weight
        vector<int> v(n+1); //value
        for (int i = 1; i <= n; i++)
            cin >> w[i] >> v[i];
        for (int i=1;i<=n;i++) //idx
            for(int j=1;j<=k;j++) //weight
            {
                int leave=dp[i-1][j];
                int take=0;
                if(w[i]<=j)
                {
                    take=v[i]+dp[i-1][j-w[i]];
                }
                dp[i][j]=max(take,leave);
            }
        cout<<"Hey stupid robber, you can get "<<dp[n][k]<<"."<<endl;
    }
    return 0;
}


