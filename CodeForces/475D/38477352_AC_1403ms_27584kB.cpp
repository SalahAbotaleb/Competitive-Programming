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
            sp[i][bit]=__gcd(sp[i][bit-1],sp[i+(1<<(bit-1))][bit-1]);
        }
}
int get_gcd(int l,int r)
{
    int dis=lg[r-l+1];
    return __gcd(sp[l][dis],sp[r-(1<<dis)+1][dis]);
}
int main()
{
    int q;
    cin>>n;
    map<int,ll>mp;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    build_table();
    for(int i=0;i<n;i++)
    {
        int gc=arr[i];
        int beg=i;
        while(beg<n) {
            int st = beg;
            int en = n - 1;
            while (st < en) {
                int mid = st + (en - st + 1) / 2;
                if (get_gcd(i, mid) == gc) {
                    st = mid;
                } else
                    en = mid - 1;
            }
            //cout<<i<<"   "<<st<<"   "<<beg<<"  "<<gc<<endl;
            mp[gc] +=(st-beg+1);
            beg=st+1;
            gc=__gcd(gc,arr[beg]);
        }
    }
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        cout<<mp[x]<<endl;
    }
    return 0;
}


