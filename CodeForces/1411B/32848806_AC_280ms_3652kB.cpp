#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool ok(ll n)
{
    ll tmp=n;
    while(tmp)
    {

        if(tmp%10!=0 && n%(tmp%10)!=0)
            return 0;
        tmp/=10;
    }
    return 1;
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        ll n;
        cin>>n;


        while(!ok(n))
        {
            n++;
        }
        cout<<n<<endl;

    }

    return 0;
}

