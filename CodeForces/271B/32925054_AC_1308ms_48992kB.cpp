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
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];

    int res=1e7;
    for(int i=0;i<n;i++)
    {
        int curr=0;
        for(int j=0;j<m;j++)
            {
                curr+=*lower_bound(primes.begin(),primes.end(),arr[i][j])-arr[i][j];
            }
            //cout<<curr<<endl;
        res=min(res,curr);
    }
    for(int i=0;i<m;i++)
    {
        int curc=0;
        for(int j=0;j<n;j++)
            {
                curc+=*lower_bound(primes.begin(),primes.end(),arr[j][i])-arr[j][i];
            }
            //cout<<curc<<endl;
        res=min(res,curc);
    }
    cout<<res<<endl;
    return 0;
}
