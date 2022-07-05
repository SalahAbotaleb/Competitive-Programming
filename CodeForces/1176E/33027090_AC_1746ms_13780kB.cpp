#include <bits/stdc++.h>
//#define oo 0x3f3f3f3f
using namespace std;
const int N=200001;
vector <vector<int>> adj;
const int oo=1e9;
int n,m;
vector <int> dis;
void bfs(int src=0)
{
    dis=vector<int>(n, oo);
    queue <int> q;
    q.emplace(src);
    dis[src]=0;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(auto ch:adj[p])
        {
            if(dis[ch]==oo)
            {
            dis[ch]=dis[p]+1;
            q.push(ch);
            }
        }
    }
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {

    cin>>n>>m;
    adj=vector<vector<int>>(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>v>>u;
        v--,u--;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    bfs(0);
    vector <int> odd,even;
    for(int i=0;i<n;i++)
    {
        if(dis[i]%2==0)
            even.push_back(i);
        else
            odd.push_back(i);
    }
    if(even.size()<odd.size())
    {
        cout<<even.size()<<endl;
        for(auto ch:even)
            cout<<ch+1<<" ";
        cout<<endl;
    }
    else
    {
        cout<<odd.size()<<endl;
        for(auto ch:odd)
            cout<<ch+1<<" ";
        cout<<endl;
    }
    }

    return 0;
}


