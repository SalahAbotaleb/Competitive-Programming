#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int N=2e5+10,M=23;
int n;
int arr[N],sp[N][M],sp2[N][M],lg[N];
void build_table()
{
    lg[1]=0;
    for(int i=2;i<N;i++)
        lg[i]=lg[i/2]+1;
    for(int i=0;i<=n;i++)
    {
        sp[i][0]=arr[i];
    }
    for(int bit=1;bit<M;bit++)
        for(int i=0;i+(1<<bit)-1<=n;i++)
        {
            sp[i][bit]=min(sp[i][bit-1],sp[i+(1<<(bit-1))][bit-1]);
        }
}
void build_table2()
{
    for(int i=0;i<=n;i++)
    {
        sp2[i][0]=arr[i];
    }
    for(int bit=1;bit<M;bit++)
        for(int i=0;i+(1<<bit)-1<=n;i++)
        {
            sp2[i][bit]=max(sp2[i][bit-1],sp2[i+(1<<(bit-1))][bit-1]);
        }
}
int get(int l,int r)
{
    if(r<l || r>=n)
        return 0;
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
int get_min(int l,int r)
{
    if(r<l || r>n)
        return INT_MAX;
    int dis=lg[r-l+1];
    return min(sp[l][dis],sp[r-(1<<dis)+1][dis]);
}
int get_max(int l,int r)
{
    if(r<l || r>n)
        return INT_MAX;
    int dis=lg[r-l+1];
    return max(sp2[l][dis],sp2[r-(1<<dis)+1][dis]);
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--) {
        int q;
        cin >> n >> q;
        for (int i = 0; i < n + 5; i++)
        {
            arr[i]=0;
            for (int j = 0; j < 20; j++)
                sp[i][j] = sp2[i][j] = 0;
        }
        string s;
        cin>>s;
        vector<int>v(n);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='-')
                v[i]=-1;
            else
                v[i]=1;
        }
        arr[0]=0;
        for(int i=1;i<=n;i++)
        {
                arr[i]+=(v[i-1]+arr[i-1]);
        }
        build_table();
        build_table2();
        while(q--)
        {
         int l,r;
         cin>>l>>r;
         int mx1=get_max(0,l-1);
         int mx2=get_max(r+1,n);
         int mn1=get_min(0,l-1);
         int mn2=get_min(r+1,n);
         if(mx2==INT_MAX) mx2=0;
         else mx2=mx2-arr[r]+arr[l-1];
         if(mn2==INT_MAX) mn2=0;
         else mn2=mn2-arr[r]+arr[l-1];
         if(mx1==INT_MAX) mx1=0;
         if(mn1==INT_MAX) mn1=0;
       // cout<<mx1<<"  "<<mx2<<"  "<<mn1<<"  "<<mn2<<endl;
        cout<<max(mx1,mx2)-min(mn1,mn2)+1<<endl;
        }
    }
    return 0;
}


