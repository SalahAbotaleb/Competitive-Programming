#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        ll arr[n+2];
        int lidx=1;
        int ridx=(n%2==0?n:n-1);
        for(int i=1;i<=n;i++)
        {
            ll x;
            cin>>x;
            //cout<<lidx<<"  "<<ridx<<"   "<<x<<endl;
            if(lidx<=n)
            {
                arr[lidx]=x;
                lidx+=2;
            }
            else
            {
                arr[ridx]=x;
                ridx-=2;
            }
        }
        for(int i=1;i<=n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

    return 0;
}
