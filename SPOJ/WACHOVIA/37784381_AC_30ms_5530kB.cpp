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
int res(int i,int weight,vector<pair<int,int>>&v,vector<vector<int>>&mem)
{
    if(i>=v.size())
        return 0;
    if(mem[i][weight]!=-1)
        return mem[i][weight];
    int opt1=-1;
    if(weight+v[i].first<=sz)
        opt1=v[i].second+res(i+1,weight+v[i].first,v,mem); //take
    int opt2=res(i+1,weight,v,mem); //leave
    return mem[i][weight]=max(opt1,opt2);
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,m;
        cin>>m>>n;
        sz=m;
        vector<vector<int>>mem(51,vector<int>(1001,-1));
        vector<pair<int,int>>v(n);
        for(auto&it:v)
        {
            cin>>it.first>>it.second;
        }
        cout<<"Hey stupid robber, you can get "<<res(0,0,v,mem)<<"."<<endl;
    }
    return 0;
}