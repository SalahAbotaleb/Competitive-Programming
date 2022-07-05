#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
vector <int> v,a;
int n;

bool valid(int idx)
{
    ll sum=0;
    for(int i=0;i<=idx;i++)
    {
        sum+=v[i];
    }
    for(int i=idx+1;i<n;i++)
    {
        if(sum>=v[i])
        {
            sum+=v[i];
        }
        else
            return 0;
    }
    return 1;
}
int bs(int l,int r)
{
    while(l<r)
    {
        int mid=l+((r-l)>>1);
        if(valid(mid))
            r=mid;
        else
            l=mid+1;
        //cout<<valid(mid)<<"   "<<mid<<endl;
    }
    return l;
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        a=v;
        sort(v.begin(),v.end());
        int s=bs(0,n-1);
        //cout<<s<<endl;
        cout<<n-s<<endl;
        int val=v[s];
        for(int i=0;i<n;i++)
        {
            if(a[i]>=val)
                cout<<i+1<<" ";
        }
        cout<<endl;
        a.clear();
        v.clear();
    }

    return 0;
}
