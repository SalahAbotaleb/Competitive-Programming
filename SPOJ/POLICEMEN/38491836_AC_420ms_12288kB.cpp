#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int N=2e5+10,M=23;
int sp[N][M];
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
    for(auto nxt:adj[curr])
    {
        if(nxt==par)
            continue;
        dfs(nxt,curr);
    }
}
int findkthancestor(int idx,int k)
{
    for(int i=M-1;i>=0;i--)
    {
        if(k&(1<<i))
            idx=sp[idx][i];
    }
    return idx;
}
int get_lca(int a,int b)
{
    if(lvl[b]>lvl[a])
        return -1;
    if(lvl[b]<lvl[a])
        swap(a,b);
     b= findkthancestor(b,lvl[b]-lvl[a]);
    if(b==a)
        return a;
    for(int i=M-1;i>=0;i--)
    {
        if(sp[b][i]==sp[a][i])
            continue;
        a=sp[a][i];
        b=sp[b][i];
    }
    return sp[a][0];
}
int main()
{
    int n;
    cin>>n;
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
        int a,b;
        cin>>a>>b;
        int ans=get_lca(a,b);
        if(ans==-1)
            cout<<"NO\n";
        else
            cout<<"YES"<<" "<<ans<<endl;
    }
    return 0;
}


