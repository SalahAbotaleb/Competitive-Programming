#include <bits/stdc++.h>
#define int long long
#define ll long long
#define el '\n'
using namespace std;
#define FIFO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int N = 3e5 + 2;
const int M=1e6+5;
int tree[N << 2],tree_mx[N<<2], arr[N];
int dv[M];
void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = arr[l];
        tree_mx[node]=arr[l];
        return;
    }
    int mid = l + r >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    tree_mx[node]=max( tree_mx[node << 1] , tree_mx[node << 1 | 1]);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

void update(int node, int l, int r, int s,int e) {
    if (l > e || r < s || tree_mx[node]<=2)
        return;
    if (l == r) {
        tree[node] = dv[tree[node]];
        tree_mx[node] = dv[tree_mx[node]];
        return;
    }
    int mid = l + r >> 1;
    update(node << 1, l, mid, s,e);
    update(node << 1 | 1, mid + 1, r, s,e);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
    tree_mx[node]=max( tree_mx[node << 1] , tree_mx[node << 1 | 1]);
}

int get(int node, int l, int r, int s, int e) {
    if (l > e || r < s)
        return 0;
    if (l >= s && r <= e)
        return tree[node];
    int mid = l + r >> 1;
    return get(node << 1, l, mid, s, e) + get(node << 1 | 1, mid + 1, r, s, e);
}

signed main() {
    FIFO
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for(int i=1;i<M;i++)
        for(int j=i;j<M;j+=i)
            dv[j]++;
    build(1, 1, n);
    while(q--)
    {
        int t,a,b;
        cin>>t>>a>>b;
        if(t==1)
        {
            update(1,1,n,a,b);
        }else
        {
            cout<<get(1,1,n,a,b)<<endl;
        }
    }
    return 0;
}


