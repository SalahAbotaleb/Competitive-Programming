#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int N=2e5+10,M=23;
int n;
int arr[N],sp[N][M],sp_idx[N][M],lg[N];
void build_table()
{
    lg[1]=0;
    for(int i=2;i<N;i++)
        lg[i]=lg[i/2]+1;
    for(int i=0;i<n;i++)
    {
        sp[i][0]=arr[i];
        sp_idx[i][0]=i;
    }
    for(int bit=1;bit<M;bit++)
        for(int i=0;i+(1<<bit)-1<=n;i++)
        {
            sp[i][bit]=min(sp[i][bit-1],sp[i+(1<<(bit-1))][bit-1]);
            if(sp[i][bit]==sp[i][bit-1])
                sp_idx[i][bit]=sp_idx[i][bit-1];
            else
                sp_idx[i][bit]=sp_idx[i+(1<<(bit-1))][bit-1];
        }
}
int get_min(int l,int r)
{
    int dis=lg[r-l+1];
    return min(sp[l][dis],sp[r-(1<<dis)+1][dis]);
}
int get_min_idx(int l,int r)
{
    int dis=lg[r-l+1];
    int ans=min(sp[l][dis],sp[r-(1<<dis)+1][dis]);
    if(ans==sp[l][dis])
        return sp_idx[l][dis];
    else
        return sp_idx[r-(1<<dis)+1][dis];
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        vector<pair<pair<int,int>,int>>v;
        vector<int>ans(n,-1);
        for(int i=0;i<n+5;i++)
        {
            for(int j=0;j<M;j++)
                sp[i][j]=sp_idx[i][j]=0;
        }
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            v.push_back({{min(a,b),max(a,b)},i});
        }
        sort(v.begin(),v.end(),[](pair<pair<int,int>,int>&a,pair<pair<int,int>,int>&b)
        {
            if(a.first.first==b.first.first)
                return a.first.second<b.first.second;
            return a.first.first<b.first.first;
        });
        int mn=1e9;
        int idx=-1;
        vector<int>tmp;
        for(int i=0;i<n;i++)
        {

            if(v[i].first.second>mn)
            {
                ans[v[i].second]=v[idx].second;
            }
            if(i==n-1)
                break;
            if(v[i].first.first<v[i+1].first.first)
            {
                if(v[i].first.second<mn)
                {
                    mn=v[i].first.second;
                    idx=i;
                }
                for(auto j:tmp)
                {
                    if(v[j].first.second<mn)
                    {
                        mn=v[j].first.second;
                        idx=j;
                    }
                }
                tmp.clear();
            }
            else
            {
                tmp.push_back(i);
            }

        }
        for(int i=0;i<n;i++)
            cout<<ans[i]+(ans[i]!=-1?1:0)<<" ";
        cout<<endl;
    }

    return 0;
}


