#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector <int> v;
    int c=0;
    int res=1;
    for(int i=2;i*i<=n;i++)
    {
       // cout<<n<<endl;
        while(n%i==0)
        {
            if(c+1<k)
            {
                c++;
                v.push_back(i);
            }
            else
                res*=i;
            n/=i;
        }
    }
    //cout<<n<<endl;
    if(n>1) res*=n;
    if(res!=1) v.push_back(res);
    if(v.size()<k)
    {
        cout<<-1<<endl;
    }else
    {
        //v.push_back(res);
        for(auto x:v)
            cout<<x<<" ";
        cout<<endl;

    }



    return 0;
}
