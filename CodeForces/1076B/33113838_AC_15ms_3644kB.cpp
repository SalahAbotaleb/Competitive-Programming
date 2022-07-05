#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n;
    cin>>n;
    //cout<<n<<endl;
    if(n%2==0)
    {
        cout<<n/2<<endl;
    }
    else
    {
        ll tmp=-1;
        for(ll i=3;i*i<=n;i+=2)
        {
            //cout<<i<<"  "<<i*i<<endl;
            if(n%i==0)
            {
                //cout<<"yes"<<endl;
                tmp=i;
                break;
            }
        }
        //cout<<tmp<<endl;
        if(tmp==-1)
            cout<<1<<endl;
        else
        {
            cout<<(n-tmp)/2+1<<endl;
        }
    }



    //cout<<"no"<<endl;

    return 0;
}

