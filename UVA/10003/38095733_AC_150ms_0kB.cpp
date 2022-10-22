#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
using namespace std;
int mem[100][100];
int pos[100];
int n;
int len;
int solve(int l,int r)
{
    if(l==r-1)
        return 0;
    if(mem[l][r]!=-1) return mem[l][r];
    int mn=INT_MAX;
    for(int i=l+1;i<r;i++)
    {
       // int plus=(l==0?pos[l]:pos[l-1])+(r==n-1?len-pos[r]:0);
        mn=min(solve(l,i)+solve(i,r)+pos[r]-pos[l],mn);
    }
    return mem[l][r]=mn;
}
int main()
{
    while(cin>>len,len)
    {
        memset(mem,-1,sizeof mem);
        cin>>n;
        pos[0]=0;
        for(int i=1;i<=n;i++)
            cin>>pos[i];
        pos[n+1]=len;
        cout<<"The minimum cutting is "<<solve(0,n+1)<<"."<<endl;
    }
    return 0;
}


