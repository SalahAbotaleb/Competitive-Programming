#include <bits/stdc++.h>
#define ll long long
#define el '\n'
using namespace std;
#define FIFO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int N=2e5+2;
int tree[N<<2],arr[N];
void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]=arr[l];
        return;
    }
    int mid= l+r >> 1;
    build(node<<1,l,mid);
    build(node<<1|1,mid+1,r);
    tree[node]=tree[node<<1]|tree[node<<1|1];
}
void update(int node,int l,int r,int idx,int val)
{
    if(l>idx || r<idx)
        return;
    if(l==r)
    {
        tree[node]=val;
        return;
    }
    int mid= l+r >> 1;
    update(node<<1,l,mid,idx,val);
    update(node<<1|1,mid+1,r,idx,val);
    tree[node]=tree[node<<1]|tree[node<<1|1];
}
int get(int node,int l,int r,int s,int e)
{
    if(l>e || r<s)
        return 0;
    if(l>=s&&r<=e)
        return tree[node];
    int mid = l+r>>1;
    return get(node<<1,l,mid,s,e)|get(node<<1|1,mid+1,r,s,e);
}
int main()
{
    //FIFO
   string s;
   cin>>s;
   for(int i=0;i<s.size();i++)
   {
       arr[i+1]=1<<(s[i]-'a');
   }
   int q;
   cin>>q;
   build(1,1,s.size());
   while(q--)
   {
       int o,a;
       cin>>o>>a;
       if(o==2)
       {
           int b;
           cin>>b;
           int val=get(1,1,s.size(),a,b);
           int cnt=0;
           while(val)
           {
               if(val&1)
                   cnt++;
               val>>=1;
           }
           cout<<cnt<<endl;
       }
       else
       {
           char c;
           cin>>c;
           update(1,1,s.size(),a,1<<(c-'a'));
       }
   }
    return 0;
}


