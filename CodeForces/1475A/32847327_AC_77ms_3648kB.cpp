#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        ll n;
        cin>>n;
    if(n%2==1)
    {
        cout<<"YES"<<endl;
        continue;
    }
        bool ok=0;
       for(ll i=2;i*i<=7;++i)
       {
           while(n%i==0)
           {
               if(i%2==1)
               {
                   ok=1;
                   break;
               }
               n/=i;
           }
       }
       if(n>1 && n%2==1) ok=1;
        if(ok)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }



    return 0;
}
