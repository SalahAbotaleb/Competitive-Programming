#include <bits/stdc++.h>
using namespace std;
const int N=200001;
vector <int> adj[N];
int n,m;
bool vis[N];
bool vis2[N];
int p;
int c=0;
bool ok=0,ok2=0;
/*void check(int s)
{
    vis2[s]=1;
    for(auto ch:adj[s])
    {
        if(vis2[ch]==1)
            continue;
        if(adj[ch].size()!=2)
            ok2=1;
        if(adj[ch].size()==2)
            check(ch);
    }
}*/
void dfs(int u,int last=-1)
{
    vis[u]=1;
    for(auto ch:adj[u])
    {
        if(!vis[ch])
        {
            if(adj[ch].size()>2)
                continue;
            dfs(ch,u);
        }
        else
        {
            if(last!=ch && last!=-1 && adj[ch].size()==2)
            {
                ok=1;
                //cout<<last+1<<"    "<<u+1<<"   "<<ch+1<<endl;
            }
                //cout<<last+1<<"    "<<u+1<<"   "<<ch+1<<endl;

        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>v>>u;
        v--,u--;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for(int i=0;i<n;i++)
    {

        if(!vis[i] && adj[i].empty()==0)
            {
                ok=ok2=0;
                p=i;
                dfs(i);
                c+=ok;
            }
    }
    cout<<c<<endl;
    return 0;
}

