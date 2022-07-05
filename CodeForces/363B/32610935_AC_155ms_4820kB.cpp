#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,w;
    cin>>n>>w;
    long long presum[n+1]= { 0 };
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        presum[i]=presum[i-1]+x;
    }
    //for(int i=1;i<=n;i++) cout<<presum[i]<<endl;
    long long m=10000000000;
    int start;
    for(int i=1;i<=n;i++)
    {
        if(i+w-1>n)
            break;
        //cout<<presum[i+w-1]<<"  "<<presum[i]<<endl;
        if(presum[i+w-1]-presum[i-1]<m)
        {
            start=i;
            m=presum[i+w-1]-presum[i-1];
        }
    }

    cout<<start<<endl;

    return 0;
}
