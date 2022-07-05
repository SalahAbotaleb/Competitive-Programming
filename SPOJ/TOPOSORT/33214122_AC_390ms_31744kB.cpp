#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e6+5;
vector <int> adj[N];
bool ok=1;
stack <int> ans;
int vis[N];
void dfs(int u)
{
    vis[u]=2;
    for(auto ch:adj[u])
    {
        if(vis[ch]==2)
            ok=0;
        if(!vis[ch])
            dfs(ch);
    }
    vis[u]=1;
    ans.push(u);
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
    }
    for(int i=0;i<n;i++)
        sort(adj[i].rbegin(),adj[i].rend());

    for(int i=n-1;i>=0;i--)
    {
        if(!vis[i])
            dfs(i);
    }
    if(ok)
    {
       while(!ans.empty())
       {
           cout<<ans.top()+1<<" ";
           ans.pop();
       }
    }
    else
    {
        cout<<"Sandro fails.";
    }
    cout<<endl;
    return 0;
}
