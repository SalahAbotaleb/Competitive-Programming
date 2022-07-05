#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
//ss
    cin>>n;
    vector <pair<int,int> > v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    bool ok=0;
    sort(v.begin(),v.end());
    for(int i=0;i<n-1;i++)
    {
        if(v[i].second>v[i+1].second)
        {
            ok=1;
            break;
        }
    }
    if(ok)
        cout<<"Happy Alex"<<endl;
    else
        cout<<"Poor Alex"<<endl;
    return 0;
}
