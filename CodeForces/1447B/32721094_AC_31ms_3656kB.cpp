#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int a,b;
        cin>>a>>b;
        int sum=0;
        int neg=0;
        int val=1000;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                int x;
                cin>>x;
                if(abs(x)<val)
                {
                    val=abs(x);
                }
                neg+=(x<0);
                sum+=abs(x);
            }

        }
        if(neg%2==1)
            sum-=val*2;
        cout<<sum<<endl;
    }


    return 0;
}
