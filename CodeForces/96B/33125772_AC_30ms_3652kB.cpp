#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
int cnt;
vector <ll> ans;
void recurse(int num)
{
    if(!num) return;
    cnt++;
    recurse(num/10);
}
void solve(ll num=0,int dig=0,int cnt7=0,int cnt4=0)
{
    if(num>=n && cnt7==cnt4)
    {
        ans.push_back(num);
    }
    if(dig>=cnt+2)
        return;
    solve(num*10+7,dig+1,cnt7+1,cnt4);
    solve(num*10+4,dig+1,cnt7,cnt4+1);
}
int main()
{
    cin>>n;
    recurse(n);
    solve();
    //cout<<cnt<<endl;
    cout<<*min_element(ans.begin(),ans.end())<<endl;

    return 0;
}
