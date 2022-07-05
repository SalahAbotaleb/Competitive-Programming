#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n;
    vector <ll> v;
    while(cin>>n)
    {
        v.push_back(n);
        sort(v.begin(),v.end());
        int siz=v.size();
        ll med=-1;
        ll pos=floor(siz/2.0);
        pos--;
        if(siz%2==0)
        {
            med=floor((v[pos]+v[pos+1])/2);
        }else
            med=v[pos+1];
        cout<<med<<endl;
    }
    return 0;
}
