#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int a,b,res;
        cin>>a>>b;
        res=a%b;
        if(res==0)
            cout<<0<<endl;
        else
            cout<<b-res<<endl;
    }


    return 0;
}
