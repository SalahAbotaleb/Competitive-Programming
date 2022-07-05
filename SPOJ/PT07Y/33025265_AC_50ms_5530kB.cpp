#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e4;
vector <int> adj[N];
int vis[N];
int cnt=0;
int ok=0;
void dfs(int u=0,int pre=-1)
{
    cnt++;
    vis[u]=1;
    for(auto ch:adj[u])
    {
        if(!vis[ch])
        {
            dfs(ch,u);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    if(m==n-1 && cnt==n)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}

