#include <bits/stdc++.h>
#define ll long long
#define el endl
using namespace std;
#define FIFO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int N=2e5+10,M=23;
int arr[N],sp[N][M];
int lvl[N];
vector<int>adj[N];
void dfs(int curr,int par)
{
    lvl[curr]=lvl[par]+1;
    sp[curr][0]=par;
    for(int i=1;i<M;i++)
    {
        int p=sp[curr][i-1];
        sp[curr][i]=sp[p][i-1];
    }
    for(auto child:adj[curr])
    {
        if(child==par)
            continue;
        dfs(child,curr);
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
int get_lca(int u,int v)
{
    if(lvl[v]<lvl[u])
        swap(u,v);
    v= getkthances(v,lvl[v]-lvl[u]);
    if(u==v)
        return u;
    for(int i=M-1;i>=0;i--)
    {
        if(sp[u][i]==sp[v][i])
            continue;
        u=sp[u][i];
        v=sp[v][i];
    }
    return sp[u][0];
}
int get_dis(int u,int v)
{
    return lvl[u]+lvl[v]-2*lvl[get_lca(u,v)];
}
int solve(int u,int v,int t)
{
    return (get_dis(u,t)+get_dis(v,t)- get_dis(u,v))/2;
}
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        u=i+2;
        cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,1);
    while(q--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        cout<<max({solve(a,b,c),solve(a,c,b),solve(b,c,a)})+1<<endl;
    }
    return 0;
}

