#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int N=2e5+10,M=23;
int n;
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
void solve(int u,int v)
{
    int dis= get_dis(u,v);
    if(dis%2==0)
    {
        if(lvl[v]<lvl[u])
            swap(u,v);
        cout <<"The fleas meet at "<< getkthances(v, dis / 2) <<"."<< endl;
        return;
    }else
    {
        if(lvl[v]<lvl[u])
            swap(u,v);
        int a =getkthances(v,dis/2);
        int b=getkthances(v,dis/2+1);
        cout<<"The fleas jump forever between "<<min(a,b)<<" and "<<max(a,b)<<"."<<endl;
    }
}
int main()
{
    int n;
    while(cin>>n,n)
    {
        for(int i=0;i<=n;i++)
            adj[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,1);
        int q;
        cin>>q;
        while(q--)
        {
            int u,v;
            cin>>u>>v;
            solve(u,v);
        }
    }
    return 0;
}


