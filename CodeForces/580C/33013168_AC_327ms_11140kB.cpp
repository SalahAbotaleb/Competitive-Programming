#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector <int> adj[N];
int n,m;
int ok[N];
int c=0;
bool vis[N];
void dfs(int u=0,int l=ok[0])
{
    vis[u]=1;
    for(auto ch:adj[u])
    {
        if(!vis[ch])
        {
        if(l+ok[ch]>m)
            continue;
        if(ok[ch]==0)
            dfs(ch,0);
        else
            dfs(ch,l+ok[ch]);

        if(adj[ch].size()==1)
        {
            //cout<<u+1<<"  "<<ch+1<<"  "<<l+ok[ch]<<endl;
            c++;
        }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>ok[i];
    }
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>v>>u;
        v--,u--;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    dfs();
    cout<<c<<endl;
    return 0;
}
