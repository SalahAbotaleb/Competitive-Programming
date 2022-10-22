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
        for (int i = 0; i < n; i++)
            cin >> w[i] >> v[i];
        for (int i=0;i<=n;i++) //idx
            for(int j=0;j<=k;j++) //weight
            {
                /*int leave=dp[i-1][j];
                int take=0;
                if(w[i]<=j)
                {
                    take=v[i]+dp[i-1][j-w[i]];
                }*/
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
                if(w[i]+j<=k)
                    dp[i+1][j+w[i]]=max(dp[i+1][j+w[i]],dp[i][j]+v[i]);
            }
        cout<<"Hey stupid robber, you can get "<<dp[n][k]<<"."<<endl;
    }
    return 0;
}


