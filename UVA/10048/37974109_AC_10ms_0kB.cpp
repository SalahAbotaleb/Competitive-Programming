#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
using namespace std;
int main()
{
    int c,s,q;
    int tc=0;
    while(cin>>c>>s>>q,c+s+q)
    {
        vector<vector<ll>>dist(c,vector<ll>(c,loo));
        while(s--)
        {
            ll u,v,c;
            cin>>u>>v>>c;
            u--,v--;
            dist[u][v]=dist[v][u]=min(dist[u][v],c);
        }
        int n=c;
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                {
                    dist[i][j]=min(dist[i][j],max(dist[i][k],dist[k][j]));
                }
        if(tc)
            cout<<endl;
        cout<<"Case #"<<++tc<<endl;
        while(q--)
        {
            int u,v;
            cin>>u>>v;
            u--,v--;
            if(dist[u][v]==loo)
                cout<<"no path\n";
            else
                cout<<dist[u][v]<<endl;
        }
    }
    return 0;
}


