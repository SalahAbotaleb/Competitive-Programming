#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        ll a,b,c,p;
        ll mm=1e18;
        cin>>p>>a>>b>>c;
        mm=min(mm,((p+a-1)/a)*a-p);
        mm=min(mm,((p+b-1)/b)*b-p);
        mm=min(mm,((p+c-1)/c)*c-p);
        cout<<mm<<endl;
    }


    return 0;
}

