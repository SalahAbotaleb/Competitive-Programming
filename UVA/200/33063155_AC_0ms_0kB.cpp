#include <bits/stdc++.h>

using namespace std;
//ofstream fout("test1.txt");
const int N=1e5;
vector <string> s;
vector <int> adj[N];
int vis[N];
int indeg[N];
/*void dfs(int p)
{
    vis[p]=1;
    for(auto ch:adj[p])
    {
        if(!vis[ch])
            dfs(ch);
    }
    char x=char(p);
    cout<<x<<" ";
}*/
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
                adj[s[i][j]].push_back(s[i+1][j]);
                indeg[s[i+1][j]]++;
                break;
            }
        }
    }

   /* for(int i=65;i<=90;i++)
        if(!vis[i]&&!adj[i].empty())
            dfs(i);*/
    queue <int> q;
        for(int i=65;i<=90;i++)
        if(!indeg[i] && !adj[i].empty())
            q.push(i);
    vector <int> ans;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        ans.push_back(p);
        for(auto ch:adj[p])
        {
            indeg[ch]--;
            if(indeg[ch]==0)
                q.push(ch);
        }
    }
    for(int i=0;i<ans.size();i++)
     {
         cout<<char(ans[i]);
     }
     cout<<endl;
    return 0;
}
