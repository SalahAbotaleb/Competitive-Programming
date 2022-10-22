#include <iostream>

#define ll long long
#define el '\n'
using namespace std;
#define FIFO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int N = 3e5 + 2;
ll tree[N << 2], arr[N];

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = arr[l];
        return;
    }
    int mid = l + r >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    tree[node] = tree[node << 1] ^ tree[node << 1 | 1];
}

void update(int node, int l, int r, int idx, ll val) {
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
}

int get(int node, int l, int r, int s, int e) {
    if (l > e || r < s)
        return 0;
    if (l >= s && r <= e)
        return tree[node];
    int mid = l + r >> 1;
    return get(node << 1, l, mid, s, e) ^ get(node << 1 | 1, mid + 1, r, s, e);
}

int main() {
    FIFO
    ll n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    build(1, 1, n);
    while (q--) {
        int opr;
        cin>>opr;
        ll idx,val;
        cin>>idx>>val;
        if(opr==1)
        update(1,1,n,idx,val);
        else
            cout<<get(1,1,n,idx,val)<<el;

    }

    return 0;
}


