#include <bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define el '\n'
using namespace std;
#define FIFO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 2;
ll tree[5][N << 2], arr[5][N];
ll n, m, k;
void build(int node, int l, int r) {
    if (l == r) {
        for (int i = 0; i < m; i++)
            tree[i][node] = arr[i][l];
        return;
    }
    int mid = l + r >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    for(int i=0;i<m;i++)
    tree[i][node] = max(tree[i][node << 1], tree[i][node << 1 | 1]);
}

/*void update(int node, int l, int r, int idx, ll val) {
    if (l > idx || r < idx)
        return;
    if (l == r) {
        tree[node] ^= val;
        return;
    }
    int mid = l + r >> 1;
    update(node << 1, l, mid, idx, val);
    update(node << 1 | 1, mid + 1, r, idx, val);
    tree[node] = tree[node << 1] ^ tree[node << 1 | 1];
}*/
int get(int node, int l, int r, int s, int e, int i) {
    if (l > e || r < s)
        return 0;
    if (l >= s && r <= e)
        return tree[i][node];
    int mid = l + r >> 1;
    return max(get(node << 1, l, mid, s, e, i), get(node << 1 | 1, mid + 1, r, s, e, i));
}
pair<pair<pair<int,int>,int>,pair<int,int>> get(int node, int l, int r, int s, int e) {
    if (l > e || r < s)
        return {{{0,0},0},{0,0}};
    if (l >= s && r <= e){
        return {{{tree[0][node],tree[1][node]},tree[2][node]},{tree[3][node],tree[4][node]}};
    }
    int mid = l + r >> 1;
    auto P1=get(node << 1, l, mid, s, e);
    auto P2= get(node << 1 | 1, mid + 1, r, s, e);
    return {{{max(P1.F.F.F,P2.F.F.F),max(P1.F.F.S,P2.F.F.S)},max(P1.F.S,P2.F.S)},{max(P1.S.F,P2.S.F),max(P1.S.S,P2.S.S)}};
}

bool ok(int s, int e) {
    auto P=get(1, 1, n, s, e);
    int res=P.F.F.F+P.F.F.S+P.F.S+P.S.F+P.S.S;
    return  res<= k;
}

int main() {
    FIFO
    cin >> n >> m >> k;
    vector<vector<int>> v;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[j][i];
        }
    }
    build(1, 1, n);
    int mx = 0;
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        int l = i, r = n;
        cnt = 0;
        while (l < r) {
            cnt++;
            int mid = l + (r - l + 1) / 2;
            if (ok(i, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        int tot = 0;
        auto P = get(1, 1, n, i, l);
        int res=P.F.F.F+P.F.F.S+P.F.S+P.S.F+P.S.S;
        if (res <= k) {
            if (l - i + 1 > mx) {
                mx = l - i + 1;
                idx = l;
            }
        }
    }
    if (mx == 0) {
        for (int i = 0; i < m; i++) {
            cout << 0 << " ";
        }
        return 0;
    }
    for (int i = 0; i < m; i++) {
        cout << get(1, 1, n, idx - mx + 1, idx, i) << " ";
    }
    return 0;
}


