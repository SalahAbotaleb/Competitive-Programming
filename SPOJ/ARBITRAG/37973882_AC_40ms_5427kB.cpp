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
        vector<pair<double, pair<int, int>>> edges;
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            string u, v;
            double c;
            cin >> u >> c >> v;
            edges.push_back({c, {mp[u], mp[v]}});
        }
        bool ok = 0;
        for (int k = 0; k < n; k++) {
            vector<double> dist(n, 0);
            dist[k] = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int from = edges[j].second.first;
                    int to = edges[j].second.second;
                    double cost = edges[j].first;
                    if (dist[from] * cost > dist[to]) {
                        dist[to] = dist[from] * cost;
                        if (i == n - 1) {
                            ok = 1;
                        }
                    }
                }
                if (ok)
                    break;
            }
        }
        printf("Case %d: ",++tc);
        cout << (ok ? "Yes\n" : "No\n") << endl;
    }
    return 0;
}


