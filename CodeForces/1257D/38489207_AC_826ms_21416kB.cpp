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
    for(int i=2;i<=n;i++)
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
    int tc;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<M;j++)
                sp[i][j]=0;
        }
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
            arr[i]=x;
        }
        int k;
        cin>>k;
        vector<int>pw(n+1,0);
        for(int i=1;i<=k;i++)
        {
            int p,d;
            cin>>p>>d;
            pw[d]=max(p,pw[d]);
        }
        for(int i=n-1;i>=0;i--)
        {
            pw[i]=max(pw[i],pw[i+1]);
        }
        build_table();
        if(get_max(0,n-1)>pw[0])
        {
            cout<<-1<<endl;
            continue;
        }
        int cnt=0;
        int beg=0;
        while(beg<n) {
            int st=1;
            int en = n ;
            while(st<en)
            {
                int mid=st+(en-st+1)/2;
                if(pw[mid]>= get_max(beg,min(beg+mid-1,n-1)))
                {
                    st=mid;
                }
                else
                {
                    en=mid-1;
                }
            }
            beg+=st;
            cnt++;
        }
        cout<<cnt<<endl;
    }

    return 0;
}


