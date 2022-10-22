#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int N=2e5+2,M=23;
int n;
int arr[N];
int sp[N][M];
int lg[N];
void build_table()
{
    lg[1]=0;
    for(int i=2;i<N;i++)
        lg[i]=lg[i/2]+1;
    for(int i=0;i<n;i++)
    {
        sp[i][0]=arr[i];
    }
    for(int bit=1;bit<M;bit++)
        for(int i=0;i+(1<<bit)-1<n;i++)
            sp[i][bit]=max(sp[i][bit-1],sp[i+(1<<(bit-1))][bit-1]);
}
int get(int l,int r)
{
    int dis=r-l+1;
    int ans=0;
    for(int i=M;i>=0;i--)
    {
        if(dis>=(1<<i))
        {
            ans+=sp[l][i];
            l+=(1<<i);
            dis-=(1<<i);
        }
    }
    return ans;
}
int get_max(int l,int r)
{
    int dis=lg[r-l+1];
    return max(sp[l][dis],sp[r-(1<<dis)+1][dis]);
}

int main()
{
    int q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int l,r;
    build_table();
    int cnt=0;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--,r--;
        int ol=l;
        if(l>r)
            swap(l,r);
        if(l==r)
        {
            cnt++;
            continue;
        }
        if(get_max(l,r-1)==arr[ol])
            cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}


