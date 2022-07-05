#include <bits/stdc++.h>
#define ll long long
using namespace std;
int store[3],cost[3],freq[3];
char recip[1000];
ll m;
bool ok(ll v)
{
    ll sum=0;
    for(int i=0;i<3;i++)
    {
        sum+=max(v*freq[i]-store[i],0ll)*cost[i];
        if(sum>m) return 0;
    }
    return 1;
}
int main()
{
    scanf("%s",&recip);
    int sz=strlen(recip);
    for(int i=0;i<sz;i++)
    {
        if(recip[i]=='B')
            freq[0]++;
        else
            if(recip[i]=='S')
                freq[1]++;
                else
                    freq[2]++;
    }
    for(int i=0;i<3;i++) scanf("%d",store+i);
    for(int i=0;i<3;i++) scanf("%d",cost+i);
    cin>>m;
    ll l=0,r=1e13;
    while(l<r)
    {
        ll mid=l+((r-l)>>1)+1;
        if(ok(mid))
            l=mid;
        else
            r=mid-1;
    }
    cout<<l<<endl;
}
