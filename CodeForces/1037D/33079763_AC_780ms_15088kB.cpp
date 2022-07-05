#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector <int> adj[N];
int path[N];

int vis[N];
int n;
bool bfs()
{
    vector <int> bpath;
    queue <int> q;
    q.push(0);
    int p;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        vis[p]=1;
        bpath.push_back(p);
        for(auto ch:adj[p])
        {
            if(!vis[ch])
            {
                q.push(ch);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
      if(path[i]!=bpath[i])
            return 0;
    }
    return 1;
}
int main()
{
    int order[N];
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++)
    {
        cin>>path[i];
        path[i]--;
        order[path[i]]=i;
    }
    for(int i=0;i<n;i++)
    {
        sort(adj[i].begin(),adj[i].end(),[&](const int a,const int b)
             {
                 return order[a]<order[b];
             }
             );
    }
    cout<<(bfs()?"YES\n":"NO\n");
    return 0;
}
