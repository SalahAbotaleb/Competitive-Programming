#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll x;
    int tc;
    cin>>tc;
    while(tc--)
    {
    cin>>x;
    if(x%2==0)
    {
        for(int i=0;i<x/2;i++)
            cout<<1;
        cout<<endl;
    }
    else
    {
        cout<<7;
        for(int i=0;i<x/2-1;i++)
            cout<<1;
        cout<<endl;
    }
    }


    return 0;
}
