#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define FIFO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int N=2e5+10,M=23;
int sp[N][M];
int lvl[N];
vector<int>adj[N];
void dfs(int curr,int par)
{
    lvl[curr]=lvl[par]+1;
    sp[curr][0]=par;
    for(int i=1;i<M;i++)
    {
        int p=sp[curr][i-1];
        sp[curr][i]=sp[p][i-1];
    }
    for(auto nxt:adj[curr])
    {
        if(nxt==par)
            continue;
        dfs(nxt,curr);
    }
}
int findkthancestor(int idx,int k)
{
    for(int i=M-1;i>=0;i--)
    {
        if(k&(1<<i))
            idx=sp[idx][i];
    }
    return idx;
}
int get_lca(int a,int b)
{
    if(lvl[b]<lvl[a])
        swap(a,b);
    b= findkthancestor(b,lvl[b]-lvl[a]);
    if(b==a)
        return a;
    for(int i=M-1;i>=0;i--)
    {
        if(sp[b][i]==sp[a][i])
            continue;
        a=sp[a][i];
        b=sp[b][i];
    }
    return sp[a][0];
}
int main()
{
    FIFO
    int tc;
    cin>>tc;
    int cc=0;
    while(tc--) {
        int n;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            adj[i].clear();
            for(int j=0;j<M;j++)
            {
                sp[i][j]=0;
            }
        }
        for (int i = 1; i <= n; i++) {
            int c;
            cin >> c;
            for (int j = 0; j < c; j++) {
                int v;
                cin >> v;
                adj[i].push_back(v);
                adj[v].push_back(i);
            }
        }
        dfs(1, 1);
        int q;
        cin >> q;
        cout<<"Case "<<++cc<<":"<<endl;
        while (q--) {
            int a, b;
            cin >> a >> b;
            cout << get_lca(a, b) << endl;
        }
    }
    return 0;
}


