#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    vector <ll> v;
    ll n,k;
    cin>>n>>k;
    for(ll i=1;i*i<=n;++i)
    {
        if(i*i==n) v.push_back(i);
        else
        if(n%i==0)
        {
            v.push_back(i);
            v.push_back(n/i);
        }
    }


    sort(v.begin(),v.end());
    if(k>v.size())
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<v[k-1]<<endl;
    }



    return 0;
}
