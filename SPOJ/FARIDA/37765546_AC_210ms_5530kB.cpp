#include <bits/stdc++.h>
#define ll long long
using namespace std;
void intit()
{
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
}

int sz;
ll res(int i,vector<ll>&v,vector<ll>&mem)
{
    if(i>=sz) return 0;
    if(mem[i]!=-1) return mem[i];
    ll opt1=v[i]+res(i+2,v,mem); //pick
    ll opt2=res(i+1,v,mem); //leave
    return mem[i]=max(opt1,opt2);
}
int main()
{
    int tc;
    cin>>tc;
    int cnt=0;
    while(tc--)
    {

        int n;
        cin>>n;
        sz=n;
        vector<ll>mem(n,-1);
        vector<ll>v(n);
        for(auto &it:v) cin>>it;
        cout<<"Case "<<++cnt<<": "<<res(0,v,mem)<<endl;
    }
    return 0;
}