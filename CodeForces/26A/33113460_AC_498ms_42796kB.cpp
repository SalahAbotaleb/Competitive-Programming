#include <bits/stdc++.h>
using namespace std;
const int N=1e7+7;
int is_prime[N];
void seive()
{
    is_prime[0]=is_prime[1]=1;
    for(int i=2;i*i<=N;i++)
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
    int n;
    cin>>n;
    int c=0;
    for(int i=1;i<=n;i++)
        if(is_prime[i]==2)
            c++;
    cout<<c<<endl;



    return 0;
}
