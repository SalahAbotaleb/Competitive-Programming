#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,p;
        cin>>n>>p;
        vector<int> v(n);
        bool swaps[n+1]={ 0 };
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        for(int i=0;i<p;i++)
        {
            int p;
            cin>>p;
            swaps[p-1]=1;
        }
        bool ok=1;
        vector <int> s=v;
        sort(s.begin(),s.end());
        for(int i=0;i<n;i++)
        {
            if(!swaps[i])
                continue;
            int j=i;
            while(j<n&&swaps[j])
                j++;
            sort(v.begin()+i,v.begin()+j+1);
        }
        for(int i=0;i<n;i++)
            if(s[i]!=v[i])
                ok=0;
        if(ok)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        }


    return 0;
}
