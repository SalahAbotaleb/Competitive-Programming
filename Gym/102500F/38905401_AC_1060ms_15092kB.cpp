#include <bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
struct node {
    node *par = this;
    ll sz = 1;
};

node *fndpar(node *u) {
    if (u->par == u)
        return u;
    return u->par = fndpar(u->par);
}

bool connect(node *u, node *v) {
    u = fndpar(u);
    v = fndpar(v);
    if (u == v)
        return 0;
    if (v->sz > u->sz) {
        u->par = v;
        v->sz += u->sz;
    } else {
        v->par = u;
        u->sz += v->sz;
    }
    return 1;
}

bool isconnected(node *u, node *v) {
    return fndpar(u) == fndpar(v);
}

int main() {
    map<int,vector<int>>mp;
    int n;
    cin >> n;
    vector<node *> nodes(n);
    for (int i = 0; i <= n; i++) nodes[i] = new node;
    for (int i = 1; i <= n; i++)
    {
        int q;
        cin>>q;
        while(q--)
        {
            int v;
            cin>>v;
            mp[v].push_back(i);
        }
    }
    vector<pair<pair<int,int>,int>>ans;
    int ts=-1;
    for(auto it:mp)
    {
        for(auto iv:it.second)
        {
            if(ts==-1)
                ts=iv;
            if(!isconnected(nodes[*it.second.begin()],nodes[iv]))
            {
            connect(nodes[*it.second.begin()],nodes[iv]);
            ans.push_back({{*it.second.begin(),iv},it.first});
            }
        }
    }
    if(ts==-1)
    {
        cout<<"impossible\n";
        return 0;
    }
    if(fndpar(nodes[ts])->sz==n)
    {
        for(auto it:ans)
            cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<endl;
    }
    else
    {
        cout<<"impossible\n";
    }
    return 0;
}
