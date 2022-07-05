#include <bits/stdc++.h>
using namespace std;
const int N=1e2+7;
vector <int> adj[N];
vector <int> ans;
int vis[N];
void dfs(int p)
{
    vis[p]=1;
    for(auto ch:adj[p])
    {
        if(!vis[ch])
            dfs(ch);
    }
    //cout<<p<<endl;
    ans.push_back(p);
}
int main()
{
    int n,m;
    while(cin>>n>>m&& n+m)
    {
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++)
            if(!vis[i])
                dfs(i);
        for(int i=0;i<n;i++)
        {
            vis[i]=0;
            adj[i].clear();
        }
        for(int i=0;i<ans.size();i++)
            printf("%d%c",ans[i]+1," \n"[i==ans.size()-1]);
        ans.clear();
    }
    return 0;
}
