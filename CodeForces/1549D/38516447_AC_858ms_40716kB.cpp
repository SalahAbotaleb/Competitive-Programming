#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int N=2e5+10,M=23;
int n;
ll arr[N],sp[N][M],lg[N];
void build_table()
{
    lg[1]=0;
    for(int i=2;i<=n;i++)
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
ll get_gcd(int l,int r)
{
    int dis=lg[r-l+1];
    return __gcd(sp[l][dis],sp[r-(1<<dis)+1][dis]);
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--) {
        int q;
        cin >> n;
        vector<ll>v(n);
        for(int i=0;i<n;i++)
            for(int j=0;j<M;j++)
                sp[i][j]=0;
        for (int i = 0; i < n; i++) {
            cin >>v[i];
        }
        for(int i=0;i<n-1;i++)
            arr[i]=abs(v[i+1]-v[i]);
        build_table();
        int mx=0;
        for(int i=0;i<n-1;i++)
        {
            int beg=0;
            ll gc=arr[i];
            int stop=i;
            int st=i;
            int en=n-2;
            while(st<en)
            {
                int mid=st+(en-st+1)/2;
                if(get_gcd(i,mid)>=2)
                {
                    st=mid;
                }
                else
                    en=mid-1;
            }
            if(get_gcd(i,st)<2)
                continue;
            mx=max(mx,st-stop+1);
            //  cout<<i<<"  "<<stop<<"  "<<st<<endl;

        }
        cout<<mx+1<<endl;
    }

    return 0;
}


