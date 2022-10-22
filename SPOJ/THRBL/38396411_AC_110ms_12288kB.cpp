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
            sp[i][j]=max(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
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
int get_max(int l,int r)
{
    int j=lg[r-l+1];
    return max(sp[l][j],sp[r-(1<<j)+1][j]);
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


