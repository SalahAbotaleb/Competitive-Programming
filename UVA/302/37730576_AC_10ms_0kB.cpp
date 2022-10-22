#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <fstream>
#include <cassert>
#include <iomanip>
#define ll long long
using namespace std;
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
struct node
{
    bool vis = 0;
    int idx = 0;
    int deg = 0;
    vector<pair<int, node*>> edge;
};
void dfs(node* src,vector<int>&ans,vector<int>&vis)
{
    src->vis=1;
    while(!src->edge.empty())
    {
        node* to=src->edge.back().second;
        int idx=src->edge.back().first;
        src->edge.pop_back();
        if(vis[idx])
            continue;
        vis[idx]=1;
        dfs(to,ans,vis);
        ans.push_back(idx);
    }

}
int main()
{
    int cnt=0;
    int u,v,idx;
    while (true)
    {

        int m=0;
        vector<node*>adj(45);
        set<int>st;
        //for (auto& it : adj) it = new node;
        for(int i=0;i<45;i++)
        {
            adj[i]=new node;
            adj[i]->idx=i;
        }
        cin>>u>>v;
        if(u==0 && v==0)
            break;
        int p=min(u,v);
         while(u+v)
         {
             cin>>idx;
             adj[u]->edge.push_back({idx,adj[v]});
             adj[v]->edge.push_back({idx, adj[u]});
             adj[u]->deg++;
             adj[v]->deg++;
             st.insert(u);
             st.insert(v);
             m++;
             cin>>u>>v;
         }
        bool ok = 1;
        for (int i = 0; i < 45; i++)
        {
            if(adj[i]->deg & 1)
            {
                ok=0;
            }
            sort(adj[i]->edge.rbegin(),adj[i]->edge.rend());
        }
        vector<int>ans;
        vector<int>vis(m+1,0);
        dfs(adj[p],ans,vis);
        if(ans.size()!=m || !ok)
            cout << "Round trip does not exist.\n";
        else
        {
            for(int i=ans.size()-1;i>=0;i--)
            {
                cout<<ans[i]<<" \n"[i==0];
            }
        }
        cout<<endl;

    }
    return 0;
}
