#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e7;
ll n;
int arr[N];
int b[N];
bool ok(int num)
{
    //bool nice=1;
    ll sum=arr[num];
    for(int i=0;i<n;i++)
    {
        if(i!=num)
        {
            if(sum>=arr[i])
            {
                sum+=arr[i];
            }
            else
                return 0;
        }
    }
    return 1;
}
int bs(int l=0,int r=n-1)
{
    int mid;
    while(l<r)
    {

        mid=l+((r-l)>>1);
        //cout<<l<<"  "<<mid<<"  "<<r<<endl;
        if(ok(mid))
            r=mid;
        else
            l=mid+1;
    }
    return r;
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
            scanf("%d",arr+i);
            b[i]=arr[i];
        }
        sort(arr,arr+n);
        int res=bs();
        vector <int> v;
        for(int i=0;i<n;i++)
        {
            if(b[i]>=arr[res])
                v.push_back(i);
        }
        sort(v.begin(),v.end());
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++)
            cout<<v[i]+1<<" \n"[i==v.size()-1];

    }

    return 0;
}
