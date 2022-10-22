#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
vector<int>primes(N,1);
void seive()
{
    primes[0]=primes[1]=0;
    for(int i=2;i<N;i++)
    {
        if(primes[i])
        {
            for(int j=i+i;j<N;j+=i)
                primes[j]=0;
        }
    }
}
int main()
{
    seive();
    vector<int>avail;
    for(int i=0;i<N;i++)
    {
        if(primes[i])
            avail.push_back(i);
    }
    int tc;
    cin>>tc;
    while(tc--)
    {
        int d;
        cin>>d;
        int f=*lower_bound(avail.begin(),avail.end(),1+d);
        int s=*lower_bound(avail.begin(),avail.end(),f+d);

        cout<<f*s<<endl;
    }
    return 0;
}
