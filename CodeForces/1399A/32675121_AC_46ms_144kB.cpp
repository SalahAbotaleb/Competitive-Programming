#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        bool ok=1;
        for(int i=0;i<n-1;i++)
        {
            if(v[i+1]-v[i]>1)
            {
                ok=0;
                break;
            }
        }
        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}
