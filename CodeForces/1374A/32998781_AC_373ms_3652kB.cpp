#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        ll x,y,n;
        cin>>x>>y>>n;
        cout<<((n-y)/x)*x+y<<endl;

    }


    return 0;
}

