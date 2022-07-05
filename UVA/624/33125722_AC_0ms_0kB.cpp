#include <bits/stdc++.h>
using namespace std;
int m,n;
int bestv,bestm;
const int N=20+5;
int arr[N];
void solve(int sum=0,int idx=0,int msk=0)
{
    if(sum>m)
        return;
    if(sum>bestv)
    {
        bestv=sum;
        bestm=msk;
    }
    if(idx==n)
        return;
    solve(sum+arr[idx],idx+1,msk|(1<<idx));
    solve(sum,idx+1,msk);
}
int main()
{
    while(cin>>m>>n)
    {
    bestm=bestv=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    solve();
    for(int i=0;i<n;i++)
    {
        if(bestm&(1<<i))
            cout<<arr[i]<<" ";
    }
    cout<<"sum:"<<bestv<<endl;
    }
    return 0;
}
