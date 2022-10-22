#include <bits/stdc++.h>

#define ll long long
#define el '\n'
using namespace std;
#define FIFO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 2;
ll tree[5][N << 2], arr[5][N];
ll n, m, k;

void build(int node, int l, int r, int i) {
    if (l == r) {
        tree[i][node] = arr[i][l];
        return;
    }
    int mid = l + r >> 1;
    build(node << 1, l, mid, i);
    build(node << 1 | 1, mid + 1, r, i);
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

bool ok(int limit) {

    int lo = 1, hi = limit;
    ll tot = 0;
    bool ok = 0;
    while (hi <= n) {
        tot=0;
        for (int i = 0; i < m; i++) {
            tot += get(1, 1, n, lo, hi, i);
        }
        ok |= (tot <= k);
        if(ok)
            return ok;
        lo++, hi++;
    }
    return ok;
}

int main() {
    //FIFO

    cin >> n >> m >> k;
    vector<vector<int>> v;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[j][i];
        }
    }
    for (int i = 0; i < m; i++)
        build(1, 1, n, i);
    int l = 1, r = n;
    while (l < r) {
        int mid = l + (r - l + 1) / 2;
        if (ok(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    int ans = l;
    int lo = 1, hi = l;
    vector<int> aa;
    while (hi <= n) {
        ll tot = 0;
        for (int i = 0; i < m; i++) {
            tot += get(1, 1, n, lo, hi, i);
        }
        if (tot <= k) {
            for (int i = 0; i < m; i++) {
                cout << get(1, 1, n, lo, hi, i) << " ";
            }
            return 0;
        }
        lo++,hi++;
    }
    for(int i=0;i<m;i++)
        cout<<0<<" ";
    return 0;
}


