#include <bits/stdc++.h>
using namespace std;
const int N=1111111;
vector <int> adj[N];
vector <int> ans;
set <int> q;
long long indeg[N];
int c=0;
void bfs()
{
    while(!q.empty())
    {
        auto it=q.begin();
        int p=*it;
        q.erase(q.begin());
        c++;
        ans.push_back(p);
        for(auto ch:adj[p])
        {
            indeg[ch]--;
            if(!indeg[ch])
               {
                   q.insert(ch);
               }

        }

        /*if(!ok)
            break;*/
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        indeg[v]++;
    }

    for(int i=0;i<n;i++)
        if(!indeg[i]) q.insert(i);
    /*if(q.size()==0)
    {
        cout<<"Sandro fails."<<endl;
        return 0;
    }*/
   // bool ok=1;
   bfs();

    if(c!=n){puts("Sandro fails.");return  0;}
	printf("%d", ans[0]+1);
	for(int i=1; i<n; i++) printf(" %d", ans[i]+1);
	printf("\n");
//ss
    return 0;
}