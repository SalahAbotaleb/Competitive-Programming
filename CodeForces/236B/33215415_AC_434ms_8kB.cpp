#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6;
//int fact[N];
/*void seive()
{
    fact[0]=fact[1]=1;
    for(int i=2;i*i<=N;i++)
    {
        if(!fact[i])
        for(int j=i;j<=N;j+=i)
        {
            fact[j]++;
        }
    }
}*/
int fact(int n)
{
    int sum=1;
    for(int i=2;i<=n;i++)
    {
        int cnt=0;
        while(n%i==0)
        {
            n/=i;
            cnt++;
        }
        sum*=(cnt+1);
    }
    return sum;
}
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    ll res=0;
    //seive();
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
            for(int k=1;k<=c;k++)
                {
                res+=fact(i*j*k);
                }
    cout<<res<<endl;

    return 0;
}
