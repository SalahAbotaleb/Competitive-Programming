#include <bits/stdc++.h>
#define ll long long
#define el '\n'
using namespace std;
#define FIFO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int N=2e5+2;
struct twins;
pair<int,int> tree[N<<2];
int arr[N];

void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]= {arr[l],0};
        return;
    }
    int mid= l+r >> 1;
    build(node<<1,l,mid);
    build(node<<1|1,mid+1,r);
    pair<int,int> p1=tree[node<<1];
    pair<int,int> p2=tree[node<<1|1];
    vector<int>v={p1.first,p2.first,p1.second,p2.second};
    sort(v.rbegin(),v.rend());
    tree[node]= {v[0],v[1]};
}
void update(int node,int l,int r,int idx,int val)
{
    if(l>idx || r<idx)
        return;
    if(l==r)
    {
        tree[node]={val,0};
        return;
    }
    int mid= l+r >> 1;
    update(node<<1,l,mid,idx,val);
    update(node<<1|1,mid+1,r,idx,val);
    pair<int,int> p1=tree[node<<1];
    pair<int,int> p2=tree[node<<1|1];
    vector<int>v={p1.first,p2.first,p1.second,p2.second};
    sort(v.rbegin(),v.rend());
    tree[node]= {v[0],v[1]};
}
pair<int,int> get(int node,int l,int r,int s,int e)
{
    if(l>e || r<s)
        return {0,0};
    if(l>=s&&r<=e)
        return tree[node];
    int mid = l+r>>1;
    pair<int,int> p1=get(node<<1,l,mid,s,e);
    pair<int,int> p2=get(node<<1|1,mid+1,r,s,e);
    vector<int>v={p1.first,p2.first,p1.second,p2.second};
    sort(v.rbegin(),v.rend());
    return {v[0],v[1]};
}
int main()
{
    //FIFO
   int n;
   cin>>n;
   for(int i=1;i<=n;i++)
       cin>>arr[i];
   int q;
   cin>>q;
   build(1,1,n);
   while(q--)
   {
       char c;
       int a;
       cin>>c>>a;
       if(c=='Q')
       {
           int b;
           cin>>b;
           pair<int,int> val=get(1,1,n,a,b);
           cout<<val.first+val.second<<endl;
       }
       else
       {
          int b;
          cin>>b;
           update(1,1,n,a,b);
       }
   }
    return 0;
}


