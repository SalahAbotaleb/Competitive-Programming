#include <bits/stdc++.h>
using namespace std;
int main()
{
    map <string,int> mp;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string x;
        cin>>x;
        if(mp.find(x)==mp.end())
        {
            cout<<"OK"<<endl;
            mp[x];
            continue;
        }
        mp[x]++;
        cout<<x<<mp[x]<<endl;


    }


    return 0;
}
