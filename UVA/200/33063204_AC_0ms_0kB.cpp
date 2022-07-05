#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
vector <string> s;
vector <int> adj[N];
int vis[N];
void dfs(int p)
{
    vis[p]=1;
    for(auto ch:adj[p])
    {
        if(!vis[ch])
            dfs(ch);
    }
    char x=char(p);
    cout<<x;
}
int main()
{
    string ss;
    while(cin>>ss && ss!="#")
    {
        s.push_back(ss);
    }
    for(int i=0;i<s.size()-1;i++)
    {
        for(int j=0;j<s[i].size()&&j<s[i+1].size();j++)
        {
            if(s[i][j]!=s[i+1][j])
            {
                adj[s[i+1][j]].push_back(s[i][j]);
                break;
            }
        }
    }

    for(int i=65;i<=90;i++)
        if(!vis[i]&&!adj[i].empty())
            dfs(i);
    cout<<endl;
    return 0;
}
