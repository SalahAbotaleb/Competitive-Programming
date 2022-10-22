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
    vector<node*> neighbour;
};
void dfs(node* src,int &cnt)
{
    cnt++;
    src->vis=1;
    for(auto it:src->neighbour)
    {
        if(!it->vis)
            dfs(it,cnt);
    }

}
void init() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}
int main()
{
    init();
    int n,m;
    cin>>n>>m;
    vector<node*>adj(n);
    for(auto&it:adj)
    {
        it=new node;
    }
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u]->neighbour.push_back(adj[v]);
        if(u!=v) adj[v]->neighbour.push_back(adj[u]);
    }
    int cnt=0;
    int cnt0=0;
    for(auto &it:adj)
        if(it->neighbour.size()==0)
            cnt0++;
    for(auto &it:adj)
    {
        if(it->neighbour.size()!=0) {
            dfs(it, cnt);
            if (n - cnt != cnt0) {
                return cout << 0, 0;
            }
            break;
        }
    }


    ll sl=0;
    ll ans=0;
    for(auto &curr:adj)
    {
        ll edges=0;
        for(auto &neigh:curr->neighbour)
        {
            if(neigh==curr)
                sl++;
            else
                edges++;
        }
        ans+=((edges)*(edges-1))/2;
    }
    ans+=(sl*(sl-1))/2;
    ans+=(1ll)*(sl)*(m-sl);
    cout<<ans;
    return 0;
}
