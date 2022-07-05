#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    vector<pair<int,int> >v;
    v.push_back({2,1});
    v.push_back({3,7});
    v.push_back({4,4});
    v.push_back({5,9});
    v.push_back({5,5});
    v.push_back({5,3});
    v.push_back({5,2});
    v.push_back({6,6});
    v.push_back({7,8});
    while(tc--)
    {
        int n;
        vector<pair<int,int> > vv;
        cin>>n;
        for(int i=0;i<9 && n>0;i++)
        {
            int x=n/v[i].first;
            if(n-v[i].first*x==1)
                x--;
            //cout<<v[i].second<<" "<<x<<endl;
            n-=x*v[i].first;
            if(x>0)
            vv.push_back({v[i].second,x});
        }

        sort(vv.begin(),vv.end(),[](pair<int,int> a,pair<int,int> b)
             {
                 return a.first>b.first;
             });
        for(int i=0;i<vv.size();i++)
        {
            cout<<vv[i].first;
            for(int j=1;j<vv[i].second;j++)
                cout<<vv[i].first;
        }
        cout<<endl;
    }


    return 0;
}
