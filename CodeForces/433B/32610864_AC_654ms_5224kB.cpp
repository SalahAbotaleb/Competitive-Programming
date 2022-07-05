#include <bits/stdc++.h>
using namespace std;
int main()
{
//ss
    int n;
    cin>>n;
    vector <long long> v (n+1 , 0);
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);
    vector <long long> c;
    c=v;
    sort(c.begin(),c.end());
    for(int i=1;i<=n;i++)
    {
        v[i]+=v[i-1];
        c[i]+=c[i-1];
        //cout<<v[i]<<" .. "<<c[i]<<endl;
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++ )
    {
        int l,r,t;
        cin>>t>>l>>r;
        if(t==1)
            cout<<v[r]-v[l-1]<<endl;
        else
            cout<<c[r]-c[l-1]<<endl;
    }

    return 0;
}
