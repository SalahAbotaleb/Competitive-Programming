#include <bits/stdc++.h>
#define ll long long
const int N=1e4+4;
using namespace std;
void pre()
{
    //ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return;
}
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
int dr8[]={1,-1,0,0,1,1,-1,-1};
int dc8[]={0,0,1,-1,1,-1,1,-1};

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int x;cin>>x;mp[x]++;
        }
        int cnt=0;
        pair<int,int> prev={0,0};
        for(auto it:mp)
        {
            if(it.first==prev.first+1)
            {
                if(it.second>prev.second)
                    cnt+=(it.second-prev.second);
            }else
            {
                cnt+=it.second;
            }

                prev=it;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
