#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
using namespace std;
int main()
{

       int n;
       cin>>n;
       vector<vector<ll>>dist(n,vector<ll>(n,loo));
       for(int i=0;i<n;i++)
           for(int j=0;j<n;j++)
           {
               ll x;
               cin>>dist[i][j];
               // dist[i][j]=dist[j][i]=min({dist[i][j],dist[j][i],x});
           }
       vector<int>avail(n,0);
       vector<int>q(n);
       vector<ll>res;
       for(auto &it:q) cin>>it;
       for(int k=0;k<n;k++) {
           int val=q.back();
           q.pop_back();
           val--;
           avail[val]=1;
           ll ans=0;
           for (int i = 0; i < n; i++)
               for (int j = 0; j < n; j++)
               {
                   dist[i][j] = min(dist[i][j], dist[i][val] + dist[val][j]);
                    if(avail[i]&&avail[j])
                        ans+=dist[i][j];
               }
           res.push_back(ans);
       }
    for(int i=n-1;i>=0;i--)
        cout<<res[i]<<" ";

    return 0;
}


