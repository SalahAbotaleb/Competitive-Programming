#include <bits/stdc++.h>
#define ll long long
const int N=1e4+4;
using namespace std;
void pre()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return;
}
struct node
{
    // 1 for black 0 for white
    int color=0;
    int idx;
    vector<node*>neigh;
};
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
int dr8[]={1,-1,0,0,1,1,-1,-1};
int dc8[]={0,0,1,-1,1,-1,1,-1};
int n;
vector<int>ans,curr;
vector<node*>adj;
bool can_be_black(int idx)
{
    for(auto it:adj[idx]->neigh)
        if(it->color==1)
            return false;
    return true;
}
void solve(int idx)
{
    if(idx==n)
    {
        if(curr.size()>ans.size())
            ans=curr;
        return;
    }
    if(n-idx+curr.size()<ans.size())
        return;
    if(can_be_black(idx))
    {
        adj[idx]->color=1;
        curr.push_back(idx);
        solve(idx+1);
        adj[idx]->color=0;
        curr.pop_back();
    }
    solve(idx+1);

}
int main()
{
    pre();
    int tc;
    cin>>tc;
    while(tc--)
    {
        int m;
        cin>>n>>m;
        adj.resize(n);
        for(int i=0;i<n;i++) adj[i]=new node(),adj[i]->idx=i;
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u]->neigh.push_back(adj[v]);
            adj[v]->neigh.push_back(adj[u]);
        }
        solve(0);
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++) cout<<ans[i]+1<<" \n"[i+1==ans.size()];
        adj.clear();
        curr.clear();
        ans.clear();
    }

    return 0;
}
