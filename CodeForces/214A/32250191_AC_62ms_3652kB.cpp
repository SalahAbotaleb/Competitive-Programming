#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    int c=0;
    int a,b;
    cin>>n>>m;
    for(int i=0;i<=1000000;i++)
    {
        a=i;
        b=n-a*a;
        if(b>=0&&a*a+b==n&&a+b*b==m)
            c++;
    }
    cout<<c<<endl;

    return 0;
}
