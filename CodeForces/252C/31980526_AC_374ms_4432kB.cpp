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
          int it=lower_bound(v.begin(),v.end(),d+v[i])-v.begin();

          if(it!=n&&v[it]>d+v[i])
            it--;
          if(it==n)
            it--;
        //cout<<"low  "<<v[it]<<endl;
          if(it-i>=2)
           {
               ll dif=it-i-1;
            c+=((dif)*(dif+1))/(2ll);
           }
         }

    }
    cout<<c<<endl;

}
