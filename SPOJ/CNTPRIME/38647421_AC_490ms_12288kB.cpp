#include <bits/stdc++.h>

#define ll long long
#define el '\n'
using namespace std;
#define FIFO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 2;
const int M = 1e6 + 5;
ll tree[N << 2], lazy[N << 2], arr[N];
vector<int>is_prime(M,1);
void propagate(int node, int l, int r) {
    if(lazy[node]==0)
        return;
    tree[node] = (r - l + 1)*is_prime[lazy[node]];
    if (l != r) {
        lazy[node << 1] = lazy[node];
        lazy[node << 1 | 1] = lazy[node];
    }
    lazy[node] = 0;
}

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = is_prime[arr[l]];
        return;
    }
    int mid = l + r >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

void update(int node, int l, int r, int s, int e,int v) {
    propagate(node, l, r);
    if (l > e || r < s)
        return;
    if (l >= s && r <= e) {
        lazy[node] = v;
        propagate(node, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(node << 1, l, mid, s, e,v);
    update(node << 1 | 1, mid + 1, r, s, e,v);
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
    int tc;
    int cc=0;
    cin>>tc;
    is_prime[0]=is_prime[1]=0;
    for(int i=2;i<M;i++)
        if(is_prime[i])
        for(ll j=1ll*i*i;j<M;j+=i)
            is_prime[j]=0;
    while (tc--) {
        int n, c;
        cin >> n >> c;
        memset(lazy,0,sizeof lazy);
       /*for(int i=0;i<=n;i++)
            tree[i]=tree[i<<1]=tree[i<<1|1]=lazy[i]=lazy[i<<1]=lazy[i<<1|1]=0;*/
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        build(1,1,n);
        cout<<"Case "<<++cc<<":"<<el;
        while (c--) {
            int t, a, b;
            cin >> t >> a >> b;
                if (t == 0) {
                    int v;
                    cin >> v;
                    update(1, 1, n, a, b, v);

                } else {
                    cout << get(1, 1, n, a, b) << el;
                }
        }

    }
    return 0;
}


