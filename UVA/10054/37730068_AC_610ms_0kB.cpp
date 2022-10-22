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
    vector<pair<node*, int>> edge;
};
void dfs(node* src,vector<int>&ans,vector<int>&vis)
{
    src->vis=1;
    while(!src->edge.empty())
    {
        node* to=src->edge.back().first;
        int idx=src->edge.back().second;
        src->edge.pop_back();
        if(vis[idx])
            continue;
        vis[idx]=1;
        dfs(to,ans,vis);
    }
    ans.push_back(src->idx);
}
int main()
{

    int tc;
    cin >> tc;
    int cnt=0;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<node*>adj(51);
        set<int>st;
        //for (auto& it : adj) it = new node;
        for(int i=0;i<51;i++)
        {
            adj[i]=new node;
            adj[i]->idx=i;
        }
        for (int i = 0; i < n; i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u]->edge.push_back({adj[v],i});
            adj[v]->edge.push_back({adj[u],i});
            adj[u]->deg++;
            adj[v]->deg++;
            st.insert(u);
            st.insert(v);
        }
        bool ok = 1;
        cnt++;
        cout<<"Case #"<<cnt<<endl;
        for (int i = 0; i < 51; i++)
        {
            if(adj[i]->deg & 1)
            {
                ok=0;
                break;
            }

        }
        vector<int>ans;
        vector<int>vis(n,0);
        dfs(adj[*st.begin()],ans,vis);
        if(ans.size()!=n+1 || !ok)
            cout << "some beads may be lost\n";
        else
        {
            for(int i=0;i<ans.size()-1;i++)
            {
                cout<<ans[i]<<" "<<ans[i+1]<<endl;
            }
        }
    if(tc!=0)
        cout<<endl;


    }
    return 0;
}
