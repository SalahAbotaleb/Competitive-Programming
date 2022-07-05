#include<bits/stdc++.h>
using namespace std;
const int N=27;
vector <int> adj[N];
stack <int> s;
int vis[N];
bool yes=1;
void dfs(int p)
{
    vis[p]=2;
    for(auto ch:adj[p])
    {
        if(vis[ch]==2)
        {
            yes=0;
        }
        if(!vis[ch])
            dfs(ch);
    }
    vis[p]=1;
    s.push(p);
}

int main()
{
    int n;
    cin>>n;
    string pre;
    string cur;
    cin>>pre;
    for(int i=1;i<n;i++)
    {
        cin>>cur;
        bool ok=1;
        for(int i=0;i<min(pre.size(),cur.size());i++)
        {
            if(pre[i]!=cur[i])
            {
                adj[pre[i]-'a'].push_back(cur[i]-'a');
                ok=0;
                //cout<<"yes"<<endl;
                break;
            }
        }
        if(ok && cur.size()<pre.size())
            {
                cout<<"Impossible"<<endl;
                return 0;
            }
        pre=cur;
    }

    for(int i=0;i<26;i++)
        {
            if(!vis[i])
                dfs(i);
        }
    if(yes)
    {
        while(!s.empty())
        {
            cout<<char(s.top()+'a');
            s.pop();
        }
    }
    else
        cout<<"Impossible";
    cout<<endl;
    return 0;
}
