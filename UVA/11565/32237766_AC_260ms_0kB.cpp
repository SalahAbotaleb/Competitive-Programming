#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {

        int a,b,c;
        cin>>a>>b>>c;
        int xx,yy,zz;
        bool ok=0;
        int s=max(a,b);
        for(int x=-s;x<=s;x++)
        {
            if(ok==1)
                break;
            for(int y=-s;y<=s;y++)
            {
                int z=a-x-y;

                    if(x!=z&&y!=z&&x!=y&&x+y+z== a && x*x+y*y+z*z==c && x*y*z==b)
                    {

                    xx=x;
                    yy=y;
                    zz=z;
                    ok=1;
                    break;
                    }
                }
            }

        if(ok)
        {
            cout<<xx<<" "<<yy<<" "<<zz<<endl;
        }else
            cout<<"No solution."<<endl;
    }


    return 0;
}
//s