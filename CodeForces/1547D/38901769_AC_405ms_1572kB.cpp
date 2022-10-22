#include <iostream>
#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int tc;
    cin>>tc;
    while(tc--) {
        int n;
        cin >> n;
        vector<int> v(n, 0);
        vector<int> ans(n, 0);
        cin>>v[0];
        for (int i = 1; i < n; i++) {
            cin >> v[i];
            if((v[i]&v[i-1])!=v[i-1])
            {
                int c=((v[i]|v[i-1])&(~v[i]));
                v[i]|=((v[i]|v[i-1])&(~v[i]));
                ans[i]=c;
            }
        }
        for(auto it:ans)
            cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}
