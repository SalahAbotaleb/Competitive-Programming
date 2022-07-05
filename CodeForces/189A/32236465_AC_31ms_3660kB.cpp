#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int a,b,c;
    int res=0;
    cin>>n>>a>>b>>c;
    for(int i=0;i<=n/a;i++)
    {
        for(int j=0;j<=n/b;j++)
        {
            int kc=n-(a*i+b*j);
            if(kc>=0&&kc%c==0)
                res=max(res,i+j+kc/c);
        }
    }
    cout<<res<<endl;
    return 0;
}
//s