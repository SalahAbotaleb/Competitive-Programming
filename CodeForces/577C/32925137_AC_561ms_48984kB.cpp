#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e7+7;
vector<int> isprime (N,1);
vector<int> primes;
void seive(ll n=N)
{
    isprime[1]=0;
    for(int i=2;i<=n;i++)
    {
        if(isprime[i]==1)
        {
            primes.push_back(i);
            for(int j=i*2;j<=n;j+=i)
                isprime[j]=0;
        }
    }
}
int main()
{
    seive();
    int n;
    cin>>n;
    vector <ll> res;
    for(int i=2;i<=n;i++)
    {
        if(isprime[i])
        {
            ll tmp=i;
            while(tmp<=n)
            {
                res.push_back(tmp);
                tmp*=i;
            }
        }
    }
    cout<<res.size()<<endl;
    for(auto x:res)
        cout<<x<<" ";

    return 0;
}
