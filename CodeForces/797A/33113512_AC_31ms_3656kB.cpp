#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int tmp;
    vector <int> v;
    tmp=n;
    for(int i=2;i*i<=n;i++)
    {
        if(tmp%i==0)
        {
            while(tmp%i==0)
            {
                tmp/=i;
                v.push_back(i);
            }
        }
    }
    if(tmp>1) v.push_back(tmp);
    if(v.size()<k)
    {
        cout<<-1<<endl;
        return 0;
    }
    int res=1;
    for(int i=0;i<v.size();i++)
    {
        if(i<k-1)
            cout<<v[i]<<" ";
        else
            res*=v[i];
    }
    if(res!=1)
        cout<<res;
    cout<<endl;


    return 0;
}
