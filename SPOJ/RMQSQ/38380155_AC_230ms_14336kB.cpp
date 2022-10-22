#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7,M=23,N=2e5+3;
int lg[N],sp[N][M],n,arr[N];
void build_table()
{
    lg[1]=0;
    for(int i=2;i<N;i++)
    {
        lg[i]=lg[i/2]+1;
    }
    for(int i=0;i<n;i++)
        sp[i][0]=arr[i];
    for(int j=1;j<M;j++)
    {
        for(int i=0;i+(1<<j)-1<n;i++)
        {
            sp[i][j]=min(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
        }
    }
}
int get(int l,int r)
{
    int j=r-l+1;
    int sum=0;
    for(int i=M;i>=0;i--)
    {
        if((1<<i)<=j)
        {
            sum+=sp[l][i];
            l+=(1<<i);
            j-=(1<<i);
        }
    }
    return sum;
}
int get_min(int l,int r)
{
    int j=lg[r-l+1];
    return min(sp[l][j],sp[r-(1<<j)+1][j]);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int q;
    cin>>q;
    build_table();
    while(q--) {
        int i, j;
        cin >> i >> j;
        cout<<get_min(i,j)<<endl;
    }
    return 0;
}


