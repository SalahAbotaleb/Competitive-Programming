#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define FIFO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int N=1e5+1,M=20;
int sp[N][M],sp_max[N][M];
int lvl[N];
vector<pair<int,int>>adj[N];
void dfs(int curr,int par,int cst)
{
    lvl[curr]=lvl[par]+1;
    sp[curr][0]=par;
    sp_max[curr][0]=cst;
    for(int i=1;i<M;i++)
    {
        int p=sp[curr][i-1];
        sp[curr][i]=sp[p][i-1];
        sp_max[curr][i]=max(sp_max[curr][i-1],sp_max[p][i-1]);
    }
    for(auto child:adj[curr])
    {
        if(child.first==par)
            continue;
        dfs(child.first,curr,child.second);
    }
}
int getkthances(int idx,int k)
{
    for(int i=M-1;i>=0;i--)
    {
        if((k>>i)&1)
            idx=sp[idx][i];
    }
    return idx;
}
pair<int,int> get_max(int idx,int k)
{
    int mx=INT_MIN;
    for(int i=M-1;i>=0;i--)
    {
        if((k>>i)&1)
        {
            mx=max(sp_max[idx][i],mx);
            idx=sp[idx][i];
        }
    }
    return {idx,mx};
}
int get_lca(int u,int v)
{
    if(lvl[v]<lvl[u])
        swap(u,v);
    auto res= get_max(v,lvl[v]-lvl[u]);
    v=res.first;
    if(u==v) {
        return res.second;
    }
    int mx=res.second;
    for(int i=M-1;i>=0;i--)
    {
        if(sp[u][i]==sp[v][i])
            continue;
        mx=max({mx,sp_max[u][i],sp_max[v][i]});
        u=sp[u][i];
        v=sp[v][i];
    }
    return max({mx,sp_max[u][0],sp_max[v][0]});
}
int get_dis(int u,int v)
{
    return lvl[u]+lvl[v]-2*lvl[get_lca(u,v)];
}
int main()
{
    FIFO
    int n;
    while(true) {
        cin>>n;
        if(n==0)
            break;
       for(int i=0;i<=n;i++)
            adj[i].clear(),lvl[i]=0;
        for (int i = 0; i <= n+1; i++)
        {
            lvl[i]=0;
            for (int j = 0; j < M; j++)
                sp[i][j] = sp_max[i][j] = 0;
        }
        for(int i=0;i<n-1;i++)
        {
            int u,v,c;
            cin>>u>>v>>c;
            adj[u].push_back({v,c});
            adj[v].push_back({u,c});
        }
        dfs(1,1,0);
        int q;
        cin>>q;
        while(q--)
        {
            int u,v;
            cin>>u>>v;
            cout<<get_lca(u,v)<<'\n';
        }
    }
    return 0;
}


