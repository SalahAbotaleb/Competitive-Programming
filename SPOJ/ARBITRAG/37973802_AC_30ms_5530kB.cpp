#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
using namespace std;
int main()
{
    int tc=0;

    int n;
    while(cin>>n,n) {
        map<string, int> mp;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            mp[s] = i;
        }
        double dist[30][30];
        for(int i=0;i<30;i++)
            for(int j=0;j<30;j++)
               dist[i][j]=0;
        for(int i=0;i<30;i++)
            dist[i][i]=1;
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            string u, v;
            double c;
            cin >> u >> c >> v;
            dist[mp[u]][mp[v]]=max(c,dist[mp[u]][mp[v]]);
        }
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    dist[i][j]=max(dist[i][j],dist[i][k]*dist[k][j]);
        bool ok=0;
        for(int i=0;i<30;i++)
            if(dist[i][i]>1)
                ok=1;
        printf("Case %d: ",++tc);
        cout << (ok ? "Yes\n" : "No\n") << endl;
    }
    return 0;
}


