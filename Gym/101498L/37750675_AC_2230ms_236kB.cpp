#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
void init() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
}
int main()
{
    init();
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,m;
        cin>>n>>m;
        vector<ll>dis(n+1,0);
        vector<pair<int,pair<int,int>>> edge;
        vector<int>indeg(n+1,0);
        for(int i=0;i<m;i++)
        {
            int u,v,c;
            cin>>u>>v>>c;
            edge.push_back({c,{u,v}});
            indeg[v]++;
        }
        bool ok=0;
        ll mn=loo;
        for(int i=0;i<n;i++)
        {
            bool isupdated=0;
            for(int j=0;j<m;j++)
            {
                int u=edge[j].S.F;
                int v=edge[j].S.S;
                ll c=edge[j].F;
                if(dis[u]+c<dis[v]) {
                    isupdated = 1;
                    dis[v] = dis[u] + c;
                    if (i == n - 1)
                        ok = 1;
                }
                mn=min({mn,(dis[v]==0?loo:dis[v]),c});
            }
            if(!isupdated)
                break;
        }
        if(ok)
        {
            cout<<"-inf\n";
            continue;
        }
        cout<<mn<<endl;
    }
    return 0;
}
