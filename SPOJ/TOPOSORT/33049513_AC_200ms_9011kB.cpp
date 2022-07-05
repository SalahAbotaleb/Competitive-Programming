#include <bits/stdc++.h>
using namespace std;
const int N=111111;
vector <int> adj[N];
vector <int> ans;
set <int> q;
long long indeg[N];
int c=0;
void  bfs() {
	int u, v;c=0;
	set< int >::iterator it;
	while(!q.empty()) {
		u = *q.begin();
		q.erase(q.begin());
		ans.push_back(u);c++;
		for(int i=0; i!=adj[u].size(); i++) {
			v = adj[u][i];
			indeg[v]--;
			if(!indeg[v]) q.insert(v);
		}
	}
}

int main()
{
    int i, j, k, u, v,m,n;
	scanf("%d%d", &n, &m);
	for(i=0; i<m; i++) {
		scanf("%d%d", &u, &v);
			adj[u].push_back(v);
		indeg[v] += 1;
	}
	for(i=1; i<=n; i++)
		if(!indeg[i])
			q.insert(i);
    /*if(q.size()==0)
    {
        cout<<"Sandro fails."<<endl;
        return 0;
    }*/
   // bool ok=1;
    bfs();
    if(c!=n){puts("Sandro fails.");return  0;}
	printf("%d", ans[0]);
	for(i=1; i<n; i++) printf(" %d", ans[i]);
	printf("\n");

    return 0;
}
