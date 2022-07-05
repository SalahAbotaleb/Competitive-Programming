#include <bits/stdc++.h>
using namespace std;
const int N=1e7+7;
int is_prime[N];
void seive()
{
    is_prime[0]=is_prime[1]=1;
    for(int i=2;i<=N;i++)
    {
        if(!is_prime[i])
        {
        for(int j=i;j<=N;j+=i)
        {
            is_prime[j]++;
        }
        }

    }
}
int main()
{
    seive();
    int tc;
    cin>>tc;
    while(tc--)
    {
    int a,b,k;
    cin>>a>>b>>k;
    int c=0;
    for(int i=a;i<=b;i++)
     {
         //cout<<is_prime[i]<<"  "<<k<<endl;
         if(is_prime[i]==k)
            c++;
     }
    cout<<c<<endl;

    }
    return 0;
}
