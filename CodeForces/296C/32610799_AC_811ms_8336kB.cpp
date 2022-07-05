#include <bits/stdc++.h>
using namespace std;
int main()
{
//ss
    int n,m,k;
    vector <pair< int , pair<int,int> > >v;
    cin>>n>>m>>k;
    long long freq[m+2]={ 0 };
    long long arr[n+2]={ 0 };
    long long presum[n+2]={ 0 };
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    v.push_back({0,{0,0}});
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({a,{b,c}});
    }
    for(int i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        freq[a]+=1;
        freq[b+1]-=1;
    }
    for(int i=1;i<=m;i++) freq[i]+=freq[i-1];
    for(int j=1;j<=m;j++)
        {
            if(freq[j]==0)
                continue;
            int x=v[j].first;
            presum[x]+=v[j].second.second*freq[j];
            presum[v[j].second.first+1]-=v[j].second.second*freq[j];
        }
    for(int i=1;i<=n;i++) presum[i]+=presum[i-1];
    for(int i=1;i<=n;i++) cout<<arr[i]+presum[i]<<" ";
    cout<<endl;


    return 0;
}
