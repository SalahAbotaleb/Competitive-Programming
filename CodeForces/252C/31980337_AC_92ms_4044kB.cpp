#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const int INF=0x3f3f3f3f,maxn=100001;
int n,d,a[maxn];
ll C(int n)
{
    return (ll)n*(n-1)/2;
}
int main()
{
    while(~scanf("%d%d",&n,&d))
    {
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            int pos=upper_bound(a,a+n,a[i]+d)-a-1;
            ans+=C(pos-i);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
