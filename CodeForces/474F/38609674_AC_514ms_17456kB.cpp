#include <bits/stdc++.h>
#define ll long long
#define el '\n'
using namespace std;
#define FIFO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int N = 3e5 + 2;
ll tree[N << 2], arr[N];
map<int,vector<int>>mp;
void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = arr[l];
        return;
    }
    int mid = l + r >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    tree[node] = __gcd(tree[node << 1] , tree[node << 1 | 1]);
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
    tree[node] = __gcd(tree[node << 1],tree[node << 1 | 1]);
}

int get(int node, int l, int r, int s, int e) {
    if (l > e || r < s)
        return 0;
    if (l >= s && r <= e)
        return tree[node];
    int mid = l + r >> 1;
    return __gcd(get(node << 1, l, mid, s, e),get(node << 1 | 1, mid + 1, r, s, e));
}

int main() {
    FIFO
    ll n, q;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        mp[arr[i]].push_back(i);
    }
    build(1, 1, n);
    cin>>q;
    while (q--) {
        int s,e;
        cin>>s>>e;
        int gc=get(1,1,n,s,e);
        int beg= lower_bound(mp[gc].begin(),mp[gc].end(),s)-mp[gc].begin();
        int en= upper_bound(mp[gc].begin(),mp[gc].end(),e)-mp[gc].begin()-1;
        if(en-beg+1>0)
            cout<<(e-s+1)-(en-beg+1)<<endl;
        else
            cout<<(e-s+1)<<endl;

    }

    return 0;
}


