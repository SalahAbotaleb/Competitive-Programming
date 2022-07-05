#include <bits/stdc++.h>
using namespace std;
long long oo=1e18+10;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int a,b,x,y,n;
        cin>>a>>b>>x>>y>>n;
        long long mm=oo;
        for(int i=0;i<=1;i++)
        {
        int aa=a,bb=b;
        int nn=n;
        int xx=min(aa-x,nn);
        nn-=xx;
        aa-=xx;
        xx=min(bb-y,nn);
        bb-=xx;
        swap(x,y);
        swap(a,b);
        mm=min(mm,(long long)aa*(long long)bb);
        }
        cout<<mm<<endl;
    }


    return 0;
}
