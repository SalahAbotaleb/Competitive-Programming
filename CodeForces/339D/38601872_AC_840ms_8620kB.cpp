#include <bits/stdc++.h>

#define ll long long
#define el '\n'
using namespace std;
#define FIFO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 2;
ll tree[N << 2], arr[N];
int lg[N];

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = arr[l];
        return;
    }
    int mid = l + r >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    if (lg[(r - l + 1)] % 2 == 1)
        tree[node] = tree[node << 1] | tree[node << 1 | 1];
    else
        tree[node] = tree[node << 1] ^ tree[node << 1 | 1];
}

void update(int node, int l, int r, int idx, ll val) {
    if (l > idx || r < idx)
        return;
    if (l == r) {
        tree[node] = val;
        return;
    }
    int mid = l + r >> 1;
    update(node << 1, l, mid, idx, val);
    update(node << 1 | 1, mid + 1, r, idx, val);
    if (lg[(r - l + 1)] % 2 == 1)
        tree[node] = tree[node << 1] | tree[node << 1 | 1];
    else
        tree[node] = tree[node << 1] ^ tree[node << 1 | 1];
}

int get(int node, int l, int r, int s, int e) {
    if (l > e || r < s)
        return 0;
    if (l >= s && r <= e)
        return tree[node];
    int mid = l + r >> 1;
    if (lg[(r - l + 1)] % 2 == 1)
        return get(node << 1, l, mid, s, e) | get(node << 1 | 1, mid + 1, r, s, e);
    else
        return get(node << 1, l, mid, s, e) ^ get(node << 1 | 1, mid + 1, r, s, e);
}

int main() {
    FIFO
    ll n, q;
    int tc = 0;
    cin >> n >> q;
    n = 1 << n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    lg[1]=0;
    for(int i=2;i<N;i++)
    {
        lg[i]=lg[i/2]+1;
    }
    build(1, 1, n);
    while (q--) {
        ll idx,val;
        cin>>idx>>val;
        update(1,1,n,idx,val);
        cout<<tree[1]<<endl;
    }

    return 0;
}


