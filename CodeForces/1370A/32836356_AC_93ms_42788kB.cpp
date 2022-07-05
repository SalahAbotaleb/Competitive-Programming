#include <bits/stdc++.h>
using namespace std;
const int N=1e7+7;
int freq[N];
int rangefact(int n)
{
    int c,great=INT_MIN,num;
    for(int i=1;i<=n;++i)
    {
        c=0;
        for(int k=i;k<=n;k+=i)
            {
                c++;
                if(c>2)
                    break;
            }
        if(i>great && c>1)
        {
            great=i;
            num=i;
        }
    }
    return num;
}
int main()
{

    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        cout<<rangefact(n)<<endl;
    }
    return 0;
}

