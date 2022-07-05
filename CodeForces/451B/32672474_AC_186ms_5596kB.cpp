#include <bits/stdc++.h>
using namespace std;
int main()
{
//s
    int n;
    cin>>n;
    vector <int> a,b;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    b=a;
    sort(b.begin(),b.end());
    vector <int> v;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
        v.push_back(i);
        }
    }
    int s,e;
    if(!v.empty())
    {
        int ok=1;
        s=v[0];
        e=v.back();
        for(int i=s,j=e;i<=e;i++,j--)
        {
            if(b[i]!=a[j])
            {
                ok=0;
                break;
            }
        }
        if(ok)
            {
                cout<<"yes"<<endl;
                cout<<s+1<<" "<<e+1<<endl;
            }
        else
            cout<<"no"<<endl;


    }
    else
    {
        cout<<"yes"<<endl;
        cout<<1<<" "<<1<<endl;
    }
    return 0;
}
