#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<ll>>dist(n,vector<ll>(n,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
        {
            string s;
            cin>>s;
            if(s[0]=='x')
                dist[i][j]=INT_MAX;
            else
            {
                dist[i][j]=stoi(s);
            }
            dist[j][i]=dist[i][j];
        }
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    ll ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        ans=max(dist[0][i],ans);
    }
    cout<<ans<<endl;
    return 0;
}


