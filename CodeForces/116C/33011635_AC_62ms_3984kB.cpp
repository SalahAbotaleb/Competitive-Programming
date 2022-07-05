#include <bits/stdc++.h>
using namespace std;
int sz=0;
const int N=1e4;
int n;
vector <int> adj[N];
vector <int> who;
int dis[N];
void bfs()
{
    queue <int> q;
    for(auto x:who)
    {
        int l=0;
        q.emplace(x);
        dis[x]=1;
        while(!q.empty())
        {
            int p=q.front();
            q.pop();
            for(auto ch:adj[p])
            {
                dis[ch]=dis[p]+1;
                q.push(ch);
            }

        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int v;
        cin>>v;
        if(v==-1)
            who.push_back(i);
        else
        {
        v--;
        adj[v].push_back(i);
        }
    }
    bfs();
    cout<<*max_element(dis,dis+n)<<endl;
    return 0;
}
