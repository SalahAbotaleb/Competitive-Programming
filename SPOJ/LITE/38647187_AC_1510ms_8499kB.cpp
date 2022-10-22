#include <bits/stdc++.h>

#define ll long long
#define el '\n'
using namespace std;
#define FIFO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 2;
const int M = 1e6 + 5;
ll tree[N << 2], lazy[N << 2], arr[N];

void propagate(int node, int l, int r) {
    if(lazy[node]==0)
        return;
    tree[node] = (r - l + 1) - tree[node];
    if (l != r) {
        lazy[node << 1] ^= lazy[node];
        lazy[node << 1 | 1] ^= lazy[node];
    }
    lazy[node] = 0;
}

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = arr[l];
        return;
    }
    int mid = l + r >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

void update(int node, int l, int r, int s, int e) {
    propagate(node, l, r);
    if (l > e || r < s)
        return;
    if (l >= s && r <= e) {
        lazy[node] ^= 1;
        propagate(node, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(node << 1, l, mid, s, e);
    update(node << 1 | 1, mid + 1, r, s, e);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

ll get(int node, int l, int r, int s, int e) {
    propagate(node, l, r);
    if (l > e || r < s)
        return 0;
    if (l >= s && r <= e)
        return tree[node];
    int mid = l + r >> 1;
    return get(node << 1, l, mid, s, e) + get(node << 1 | 1, mid + 1, r, s, e);
}

int main() {
    //FIFO
    int tc = 1;
    while (tc--) {
        int n, c;
        cin >> n >> c;
        while (c--) {
            int t, a, b;
            cin >> t >> a >> b;
            if (t == 0) {

                update(1, 1, n, a, b);

            } else {
                cout << get(1, 1, n, a, b) << el;
            }

        }

    }
    return 0;
}


