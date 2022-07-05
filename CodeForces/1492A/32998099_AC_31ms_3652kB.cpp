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
        cout<<min({(p+a-1)/a*a,(p+b-1)/b*b,(p+c-1)/c*c})-p<<endl;
    }


    return 0;
}

