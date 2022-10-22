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
void dfs(node* src,vector<int>&ans)
{
    src->vis=1;
    while(!src->edge.empty())
    {
        node* to=src->edge.back().first;
        src->edge.pop_back();
        dfs(to,ans);
    }
    ans.push_back(src->idx);
}
int main()
{

    int tc=1;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<node*>adj(400005);
        set<int>st;
        for(int i=0;i<400005;i++)
        {
            adj[i] = new node;
            adj[i]->idx=i;
        }
        map<string,int>mp;
        map<int,string>mp2;
        int idx=0;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            string s1=s.substr(0,2);
            string s2=s.substr(1,2);

            if(mp.find(s1)==mp.end())
            {
                mp[s1]=idx;
                mp2[idx]=s1;
                idx++;
            }
            if(mp.find(s2)==mp.end())
            {
                mp[s2]=idx;
                mp2[idx]=s2;
                idx++;
            }
            adj[mp[s1]]->edge.push_back({adj[mp[s2]],i});
            adj[mp[s1]]->outdeg++;
            adj[mp[s2]]->indeg++;
            st.insert(mp[s1]);
            st.insert(mp[s2]);
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
        if(!(cnt1==cnt2 && (cnt1==1||cnt1==0) && ok==1))
        {
            cout<<"NO\n";
            continue;
        }
        vector<int>ans;
        if(beg!=-1)
        {
            dfs(adj[beg],ans);
        }
        else
        {
            dfs(adj[*st.begin()],ans);
        }
        if(ans.size()!=n+1)
            ok=0;
        if(!ok)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            for(int i=ans.size()-1;i>=0;i--)
            {
                if(i==0)
                    cout<<mp2[ans[i]];
                else
                    cout<<mp2[ans[i]][0];
            }
        }


    }
    return 0;
}
