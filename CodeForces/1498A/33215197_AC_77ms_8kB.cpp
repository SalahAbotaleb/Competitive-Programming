#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll sum(ll x)
{
    ll res=0;
    while(x>0)
     {
         res+=x%10;
         x/=10;
     }
     return res;
}
int main()
{
    ll tc;
    cin>>tc;
    while(tc--)
    {
     cin>>n;
     while(__gcd(n,sum(n))==1)
    {
               n++;
    }
     cout<<n<<endl;

    }

    return 0;
}
