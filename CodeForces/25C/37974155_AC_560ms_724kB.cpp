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
            cin>>dist[i][j];
    int c;
    cin>>c;
    while(c--)
    {
        ll u,v,cst;
        cin>>u>>v>>cst;
        u--,v--;
        dist[u][v]=dist[v][u]=min(dist[u][v],cst);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dist[i][j]=min({dist[i][j],dist[i][u]+dist[u][v]+dist[v][j],dist[i][v]+dist[v][u]+dist[u][j]});
        ll ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<i;j++)
                ans+=dist[i][j];
        cout<<ans<<" ";
    }


    return 0;
}


