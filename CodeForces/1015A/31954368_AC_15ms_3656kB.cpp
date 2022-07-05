#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector <bool> v(m+2,0);
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
            for(int j=l;j<=r;j++)
            {
                v[j]=1;
            }
    }
     int c=0;
     vector <int> pos;
     for(int i=1;i<m+1;i++)
     {

         if(v[i]==0)
         {
             c++;
             pos.push_back(i);
         }
     }
    cout<<c<<endl;
    for(int i=0;i<pos.size();i++)
        cout<<pos[i]<<" \n"[i==pos.size()-1];

    return 0;
}
