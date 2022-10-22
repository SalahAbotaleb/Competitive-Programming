#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
using namespace std;
int main()
{
   int tc;
   cin>>tc;
   int kk=0;
   while(tc--)
   {
       vector<vector<ll>>dist1(26,vector<ll>(26,INT_MAX));
       vector<vector<ll>>dist2(26,vector<ll>(26,INT_MAX));
       int n;
       cin>>n;
       if(kk!=0)
           cout<<endl;
       kk++;
       for(int i=0;i<n;i++)
       {
           char a,b;
           cin>>a>>b;
           dist1[a-'A'][b-'A']=1;
       }
       cin>>n;
       for(int i=0;i<n;i++)
       {
           char a,b;
           cin>>a>>b;
           dist2[a-'A'][b-'A']=1;
       }
       for(int k=0;k<26;k++)
           for(int i=0;i<26;i++)
               for(int j=0;j<26;j++)
                   dist1[i][j]=min(dist1[i][j],dist1[i][k]+dist1[k][j]);
       for(int k=0;k<26;k++)
           for(int i=0;i<26;i++)
               for(int j=0;j<26;j++)
                   dist2[i][j]=min(dist2[i][j],dist2[i][k]+dist2[k][j]);
       bool ok=1;
       for(int i=0;i<26;i++)
           for(int j=0;j<26;j++)
               if(dist1[i][j]!=INT_MAX||dist2[i][j]!=INT_MAX)
               {
                   if(dist1[i][j]==INT_MAX||dist2[i][j]==INT_MAX)
                       ok=0;
               }
       cout<<(ok?"YES\n":"NO\n");
   }


    return 0;
}


