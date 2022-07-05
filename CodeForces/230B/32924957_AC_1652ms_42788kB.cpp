#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e7+7;
vector<int> isprime (N,1);
void seive(ll n=N)
{
    isprime[1]=0;
    for(int i=2;i<=n;i++)
    {
        if(isprime[i]==1)
        {
            for(int j=i*2;j<=n;j+=i)
                isprime[j]=0;
        }
    }
}
int main()
{
    seive();
    ll tc;
    cin>>tc;
    while(tc--)
    {
        ll n;
        cin>>n;
        ll sq=sqrt(n);
        if(isprime[sq] && (ll)1*sq*sq==n)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }



    return 0;
}
