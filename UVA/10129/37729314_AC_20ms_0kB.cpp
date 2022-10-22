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
    int indeg = 0;
    int outdeg = 0;
    vector<pair<node*, int>> edge;
};
void dfs(node* src)
{
    src->vis=1;
    while(!src->edge.empty())
    {
        node* to=src->edge.back().first;
        src->edge.pop_back();
        dfs(to);
    }
}
int main()
{

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<node*>adj(26);
        set<int>st;
        for (auto& it : adj) it = new node;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            adj[s[0]-'a']->edge.push_back({adj[s.back()-'a'],i});
            adj[s[0] - 'a']->outdeg++;
            st.insert(s[0]-'a');
            st.insert(s.back()-'a');
            adj[s.back() - 'a']->indeg++;
        }
        bool ok = 1;
        int cnt1 = 0;
        int cnt2 = 0;
        int beg=-1;
        for (int i = 0; i < 26; i++)
        {
            if(abs(adj[i]->indeg-adj[i]->outdeg)>1)
            {
                ok=0;
                break;
            }
            if(adj[i]->indeg>adj[i]->outdeg)
                cnt1++;
            if(adj[i]->outdeg>adj[i]->indeg)
                cnt2++,beg=i;
        }
        if(!(cnt1==cnt2 && (cnt1==1||cnt1==0) && ok==1))
        {
            cout<<"The door cannot be opened.\n";
            continue;
        }
        if(beg!=-1)
        {
            dfs(adj[beg]);
        }
        else
        {
            dfs(adj[*st.begin()]);
        }
        for(auto it:st)
            if(!adj[it]->vis)
                ok=0;
        if(!ok)
            cout<<"The door cannot be opened.\n";
        else
            cout<<"Ordering is possible.\n";

    }
    return 0;
}
