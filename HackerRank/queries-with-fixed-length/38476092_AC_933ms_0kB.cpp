#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int N=2e5+10,M=23;
int n;
int arr[N],sp[N][M],lg[N];
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
        for(int i=0;i+(1<<bit)-1<=n;i++)
        {
            sp[i][bit]=max(sp[i][bit-1],sp[i+(1<<(bit-1))][bit-1]);
        }
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
    for(int i=0;i<n;i++) cin>>arr[i];
    build_table();
    while(q--)
    {
        int x;cin>>x;
            int mx=INT_MAX;
            for(int j=0;j<=n-x;j++)
            {
                // cout<<i<<"  "<<j<<"  "<<j+i-1<<endl;
                mx=min(mx,get_max(j,j+x-1));
            }
            cout<<mx<<endl;
    }
    return 0;
}


