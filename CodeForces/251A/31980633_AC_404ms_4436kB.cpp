#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,d;
    cin>>n>>d;
    vector<ll> v(n);
    for(auto &x:v) cin>>x;
    ll c=0;
    if(n>=3)
    {
         for(int i=0;i<n;++i)
         {
          ll it=lower_bound(v.begin(),v.end(),d+v[i])-v.begin();

          if(it!=n&&v[it]>d+v[i])
            it--;
          if(it==n)
            it--;
          if(it-i>=2)
           {
            c+=((it-i-1)*(it-i))/(2ll);
           }
         }

    }
    cout<<c<<endl;

}
