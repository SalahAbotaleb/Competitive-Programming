#include <bits/stdc++.h>
using namespace std;
const int N=1e4+4;
vector <int> adj[N];
bool ok=0;
int vis[N];
int c=0;
void dfs(int p,int pp=-1)
{
    c++;
    vis[p]=1;
    for(auto ch:adj[p])
    {

        if(!vis[ch])
            dfs(ch,p);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(m!=n-1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    dfs(0);
    if(c!=n)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    return 0;
}
