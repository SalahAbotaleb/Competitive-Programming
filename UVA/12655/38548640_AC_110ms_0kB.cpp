#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define FIFO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int N=1e5+2,M=20;
int sp[N][M],sp_max[N][M];
int lvl[N];
vector<pair<int,int>>adj[N];
struct node
{
    node* par = this;
    ll sz = 1;
    int idx;
    int color = 0;
    vector<int>ans;
};
node* fndpar(node* u)
{
    if (u->par == u)
        return u;
    return u->par = fndpar(u->par);
}
bool connect(node* u, node* v)
{
    u = fndpar(u);
    v = fndpar(v);
    if (u == v)
        return 0;
    if (v->sz > u->sz)
    {
        u->par = v;
        v->sz += u->sz;
        for (int i = 0; i < u->ans.size(); i++)
            v->ans.push_back(u->ans[i]);
    }
    else
    {
        v->par = u;
        u->sz += v->sz;
        for (int i = 0; i < v->ans.size(); i++)
            u->ans.push_back(v->ans[i]);

    }
    return 1;
}
bool isconnected(node* u, node* v)
{
    return fndpar(u) == fndpar(v);
}
int MST(vector<pair<int, pair<int, int>>>& v, vector<node*>& nodes)
{
    int cost = 0;
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < v.size(); i++)
    {
        int from = v[i].second.first;
        int to = v[i].second.second;
        if (!isconnected(nodes[from], nodes[to]))
        {
            adj[from].push_back({to,v[i].first});
            adj[to].push_back({from,v[i].first});
            connect(nodes[from], nodes[to]);
            cost += v[i].first;
        }
    }
    return cost;
}
void dfs(int curr,int par,int cst)
{
    lvl[curr]=lvl[par]+1;
    sp[curr][0]=par;
    sp_max[curr][0]=cst;
    for(int i=1;i<M;i++)
    {
        int p=sp[curr][i-1];
        sp[curr][i]=sp[p][i-1];
        sp_max[curr][i]=min(sp_max[curr][i-1],sp_max[p][i-1]);
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
    int mx=INT_MAX;
    for(int i=M-1;i>=0;i--)
    {
        if((k>>i)&1)
        {
            mx=min(sp_max[idx][i],mx);
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
        mx=min({mx,sp_max[u][i],sp_max[v][i]});
        u=sp[u][i];
        v=sp[v][i];
    }
    return min({mx,sp_max[u][0],sp_max[v][0]});
}
int get_dis(int u,int v)
{
    return lvl[u]+lvl[v]-2*lvl[get_lca(u,v)];
}
int main()
{
    FIFO
    int n,m,s;
    while(cin>>n>>m>>s) {
        
        vector<node*>nodes(n + 1);
        for (int i = 0; i < n + 1; i++) nodes[i] = new node, nodes[i]->idx = i, nodes[i]->ans.push_back(i);

        for(int i=0;i<=n;i++)
            adj[i].clear(),lvl[i]=0;
        for (int i = 0; i <= n+1; i++)
        {
            lvl[i]=0;
            for (int j = 0; j < M; j++)
                sp[i][j] = sp_max[i][j] = 0;
        }
        vector<pair<int,pair<int,int>>>par;
        for(int i=0;i<m;i++)
        {
            int u,v,c;
            cin>>u>>v>>c;
            par.push_back({c,{u,v}});
        }
        MST(par,nodes);
        dfs(1,1,0);
        while(s--)
        {
            int u,v;
            cin>>u>>v;
            cout<<get_lca(u,v)<<'\n';
        }
    }
    return 0;
}


