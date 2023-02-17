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
vector<vector<int>>v;
int rc,cc;
pair<int,int> horz_BS(int lo,int up,int rw)
{
    int beg,en=0;
    int l=0,r=cc-1;
    int l1=-1;
    while(l<=r)
    {
        int md=l+(r-l+1)/2;
        if(v[rw][md]>=lo)
            l1=md,r=md-1;
            else
            l=md+1;
    }
    l=0,r=cc-1;
    int l2=-1;
    while(l<=r)
    {
        int md=l+(r-l+1)/2;
        if(v[rw][md]<=up)
            l2=md,l=md+1;
            else
                r=md-1;
    }

    if(l2==-1||l1==-1 || l2<l1)
        return {-1,-1};

    return {l1,l2};
}

int vert_BS(int lo,int up,int cl,int l)
{
    int r=rc-1;
    int ans=0;
    while(l<=r)
    {
        int md=l+(r-l+1)/2;
        if(v[md][cl]<=up)
            ans=md,l=md+1;
        else
            r=md-1;
    }
    return ans;
}
int BS(int lo,int up,int l1,int l2,int rr)
{
    int l=l1,r=l2,ans=0;

    while(l<=r)
    {
        int md=l+(r-l+1)/2;

        if((vert_BS(lo,up,md,rr)-rr+1)>=(md-l1+1))
            ans=md,l=md+1;
        else
            r=md-1;
    }
    return ans-l1+1;
}
int solve(int lo,int up)
{
    int mx=0;
for(int i=0;i<rc;i++)
{
    pair<int,int> limit= horz_BS(lo,up,i);
    if(limit.first==-1&&limit.second==-1)
        continue;
    mx=max(mx,BS(lo,up,limit.first,limit.second,i));
}
return mx;
}
int main()
{

   while(cin>>rc>>cc&&rc)
   {
      v.resize(rc,vector<int>(cc));
      for(int i=0;i<rc;i++)
          for(int j=0;j<cc;j++)
              cin>>v[i][j];
      int q;
      cin>>q;
      while(q--)
      {
        int l,u;
        cin>>l>>u;
        cout<<solve(l,u)<<endl;

      }

      cout<<"-\n";
       v.clear();
   }
    return 0;
}
