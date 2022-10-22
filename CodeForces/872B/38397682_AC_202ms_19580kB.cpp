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
            sp[i][bit]=min(sp[i][bit-1],sp[i+(1<<(bit-1))][bit-1]);
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
int get_min(int l,int r)
{
    int dis=lg[r-l+1];
    return min(sp[l][dis],sp[r-(1<<dis)+1][dis]);
}

int main()
{
    int q;
    cin>>n>>q;
   int mx=INT_MIN;
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
       if(arr[i]>mx)
       {
           mx=arr[i];
       }
   }
   if((arr[0]==mx||arr[n-1]==mx)&&q>=2)
   {
       cout<<mx<<endl;
       return 0;
   }
   if(q>2)
   {
       cout<<mx<<endl;
       return 0;
   }
   build_table();
   if(q==1)
   {
       cout<<get_min(0,n-1);
   }else
   {
       int mmx=INT_MIN;
        for(int i=0;i<n-1;i++)
        {
            mmx=max(mmx,max(get_min(0,i),get_min(i+1,n-1)));
        }
        cout<<mmx<<endl;
   }

    return 0;
}


