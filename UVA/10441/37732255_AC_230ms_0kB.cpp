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
    vector<pair<node*, string>> edge;
};
void dfs(node* src,vector<string>&ans)
{
    src->vis=1;
    while(!src->edge.empty()) {
        node *to = src->edge.back().first;
        string s = src->edge.back().second;
        src->edge.pop_back();
        dfs(to, ans);
        ans.push_back(s);
    }
}
int main()
{

    int tc;
    cin>>tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<node*>adj(400005);
        for(int i=0;i<400005;i++)
        {
            adj[i] = new node;
            adj[i]->idx=i;
        }
        map<string,vector<string>>mp;
        set<int>st;
        int idx=0;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            st.insert(s[0]-'a');
            st.insert(s.back()-'a');
            adj[s[0]-'a']->edge.push_back({adj[s.back()-'a'],s});
            adj[s[0]-'a']->outdeg++;
            adj[s.back()-'a']->indeg++;
            string s2=s.substr(0,1)+s.substr(s.size()-1,1);
            mp[s2].push_back(s);
        }
        bool ok = 1;
        int cnt1 = 0;
        int cnt2 = 0;
        int beg=-1;
        for (int i = 0; i < 400005; i++)
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
        for(auto &it:adj)
        {
            sort(it->edge.begin(),it->edge.end(),[](pair<node*,string>a,pair<node*,string>b)
            {
                return a.second>b.second;
            });
        }
        if(!(cnt1==cnt2 && (cnt1==1||cnt1==0) && ok==1))
        {
            cout<<"***\n";
            continue;
        }
        vector<string>ans;
        if(beg!=-1)
        {
            dfs(adj[beg],ans);
        }
        else
        {
            dfs(adj[mp.begin()->first[0]-'a'],ans);
        }
        if(ans.size()!=n)
            ok=0;
        if(!ok)
            cout<<"***\n";
        else
        {
            for(int i=ans.size()-1;i>=0;i--)
            {
                cout<<ans[i]<<".\n"[i==0];
            }
        }


    }
    return 0;
}
