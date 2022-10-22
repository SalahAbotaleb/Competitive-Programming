#include <bits/stdc++.h>
#define ll long long
#define el endl
using namespace std;
#define FIFO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int N=2e5+10,M=23;
int timer;
int arr[N],sp[N][M],sp_rev[N][M];
int lvl[N],in[N],out[N];
vector<int>adj[N];
map<int,vector<int>>mp;
void dfs(int curr,int par)
{
    lvl[curr]=lvl[par]+1;
    in[curr]=timer++;
    mp[lvl[curr]].push_back(in[curr]);
    sp[curr][0]=par;
    for(int i=1;i<M;i++)
    {
        int p=sp[curr][i-1];
        sp[curr][i]=sp[p][i-1];
    }
    for(auto child:adj[curr])
    {
        if(child==par) {
            continue;
        }
        dfs(child,curr);
    }
    out[curr]=timer;
    mp[lvl[curr]].push_back(out[curr]);
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
bool is_ca(int u,int v,int c)
{
    return in[c]<=min(in[u],in[v])&&out[c]>=max(out[u],out[v]);
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

int main()
{
    int n;
    cin>>n;
    vector<int>beg;
    for(int i=0;i<n;i++)
    {
        int u,v;
        u=i+1;
        cin>>v;
        if(v==0)
        {
            beg.push_back(i+1);
            continue;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(auto it:beg)
    {
        dfs(it,0);
    }
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            int p=sp[j][i];
            sp_rev[p][i]++;
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int u,k;
        cin>>u>>k;
        int p= getkthances(u,k);
       /* for(auto it:mp[lvl[u]])
            if(it.first>in[p]&&it.second<out[p])
                cnt++;*/
       int en= upper_bound(mp[lvl[u]].begin(),mp[lvl[u]].end(),out[p])-mp[lvl[u]].begin()-1;
       int beg=lower_bound(mp[lvl[u]].begin(),mp[lvl[u]].end(),in[p])-mp[lvl[u]].begin();
       // cout<<beg<<"  "<<en<<endl;
       int cnt=(en-beg+1)/2;
       if(cnt!=0)
            cnt--;
        cout<<cnt<<" ";
    }
    return 0;
}

