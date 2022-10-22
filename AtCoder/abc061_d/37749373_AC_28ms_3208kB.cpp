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
#define F first
#define S second
using namespace std;
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<m;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        edges.push_back({-c,{u,v}});
    }
    vector<ll>dis(n+1,loo);
    bool ok=0;
    dis[1]=0;
    for(int i=0;i<2*n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int u = edges[j].S.F;
            int v= edges[j].S.S;
            int c= edges[j].F;
            if(c+dis[u]<dis[v])
            {
                dis[v]=c+dis[u];
                if(i==2*n-1 && v==n)
                {
                    ok=1;
                }
            }
        }
    }
    if(ok)
    {
        return cout<<"inf",0;
    }
    cout<<-dis[n];
    return 0;
}
