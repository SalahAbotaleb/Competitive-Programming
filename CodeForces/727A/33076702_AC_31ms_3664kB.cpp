#include <bits/stdc++.h>
using namespace std;
int x,y;
bool ok=1;
vector <int> ans;
void who(int p)
{
    ans.push_back(p);
    if(p==x)
        return;
    if(p<x)
    {
        ok=0;
        return;
    }
    if(p%2==0)
        who(p/2);
    else
    {
        int xx=p-1;
        if((p-1)%10==0)
            who((p-1)/10);
        else
        {
            ok=0;
            return;
        }
    }

}
int main()
{
    cin>>x>>y;
    who(y);
    if(ok)
    {
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        for(int i=ans.size()-1;i>=0;i--)
            cout<<ans[i]<<" ";
    }
    else
        cout<<"NO"<<endl;

    return 0;
}
