#include <bits/stdc++.h>

#define ll long long
#define el '\n'
using namespace std;
#define FIFO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 2;
const int M = 1e6 + 5;
ll tree[N << 2],tree_min[N<<2] ,lazy[N << 2], arr[N];

void propagate(int node, int l, int r) {
    if (lazy[node] == 0)
        return;
    tree[node] += (r - l + 1) * (lazy[node]);
    tree_min[node]+=lazy[node];
    if (l != r) {
        lazy[node << 1] += lazy[node];
        lazy[node << 1 | 1] += lazy[node];
    }
    lazy[node] = 0;
}

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = arr[l];
        tree_min[node]=arr[l];
        return;
    }
    int mid = l + r >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
    tree_min[node]=min(tree_min[node << 1] ,tree_min[node << 1 | 1]);
}

void update(int node, int l, int r, int s, int e, ll val) {
    propagate(node, l, r);
    if (l > e || r < s)
        return;
    if (l >= s && r <= e) {
        lazy[node] += val;
        propagate(node, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(node << 1, l, mid, s, e, val);
    update(node << 1 | 1, mid + 1, r, s, e, val);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
    tree_min[node] = min(tree_min[node << 1] , tree_min[node << 1 | 1]);
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
ll get_min(int node, int l, int r, int s, int e) {
    propagate(node, l, r);
    if (l > e || r < s)
        return loo;
    if (l >= s && r <= e)
        return tree_min[node];
    int mid = l + r >> 1;
    return min(get_min(node << 1, l, mid, s, e),get_min(node << 1 | 1, mid + 1, r, s, e));
}
int main() {
    FIFO
    int tc=1;
    while (tc--) {
        int n,q;
        cin >> n;
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        build(1, 1, n);
        cin>>q;
        cin.ignore();
        while (q--) {
            string s;
            stringstream ss;
            getline(cin,s);
            ss<<s;
            int tc=count(s.begin(),s.end(),' ');
            if(tc==1)
            {
                int l,r;
                ss>>l>>r;
                l++,r++;
                if(l>r)
                {
                    int l1=1;
                    int r1=r;
                    int l2=l;
                    int r2=n;
                    cout<<min(get_min(1,1,n,l1,r1),get_min(1,1,n,l2,r2))<<el;
                }else
                {
                    cout<<get_min(1,1,n,l,r)<<el;
                }
            }else
            {
                int l,r,v;
                ss>>l>>r>>v;
                l++,r++;
                if(l>r)
                {
                    int l1=1;
                    int r1=r;
                    int l2=l;
                    int r2=n;
                    update(1,1,n,l1,r1,v);
                    update(1,1,n,l2,r2,v);
                }else
                {
                    update(1,1,n,l,r,v);
                }
            }
            ss.clear();
        }

    }
    return 0;
}


