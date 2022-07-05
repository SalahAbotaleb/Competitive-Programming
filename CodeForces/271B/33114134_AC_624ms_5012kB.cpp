#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int is_prime[N];
int n,m;
int arr[500][500];
void seive()
{
    is_prime[0]=is_prime[1]=1;
    for(int i=2;i*i<=N;i++)
    {
        if(!is_prime[i])
        {
        for(int j=i*i;j<=N;j+=i)
        {
            is_prime[j]=1;
        }
        }

    }
}
int who(int v)
{
    //cout<<v<<endl;
    for(int i=v;i<=N;i++)
    {
        //cout<<v<<"  .  "<<is_prime[i]<<endl;
        if(is_prime[i]==0)
            return i;
    }
}
int main()
{
    seive();
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    int res=1e7;
    for(int i=0;i<n;i++)
    {
        int cur=0;
        for(int j=0;j<m;j++)
            cur+=who(arr[i][j])-arr[i][j];
        res=min(res,cur);
    }
    for(int i=0;i<m;i++)
    {
        int cur=0;
        for(int j=0;j<n;j++)
            cur+=(who(arr[j][i])-arr[j][i]);
        res=min(res,cur);
    }
    cout<<res<<endl;
    return 0;
}

