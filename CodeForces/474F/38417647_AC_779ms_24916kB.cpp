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
    cin>>n;
    unordered_map<int,vector<int>>mp;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        mp[arr[i]].push_back(i);
    }
    build_table();
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--,r--;
        int gc=get_gcd(l,r);
        if(mp.find(gc)==mp.end())
            cout<<r-l+1<<endl;
        else
        {
            auto fnd= lower_bound(mp[gc].begin(),mp[gc].end(),l);
            if(fnd==mp[gc].end()||(fnd-mp[gc].begin())>r)
            {
                cout<<r-l+1<<endl;
                continue;
            }
            int dis=r-l+1;
            int beg= lower_bound(mp[gc].begin(), mp[gc].end(),l)-mp[gc].begin();
            int en=upper_bound(mp[gc].begin(), mp[gc].end(),r)-mp[gc].begin();
            en--;
            int cnt=en-beg+1;
            cout<<dis-cnt<<endl;
            //cout<<dis<<"  "<<st-l+1<<endl;

        }
    }
    return 0;
}


