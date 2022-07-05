#include <bits/stdc++.h>
using namespace std;
int finddiv(int n)
{
    int num=1;
    for(auto x:{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97})
    {
         int pow=0;
         int sum=0;
         while(1)
         {
             pow++;
             int val=1;
             for(int i=1;i<=pow;i++)
             {
                 val*=x;
             }
             if(n%val!=0)
                break;
            if(pow==1)
                sum++;
            sum++;
         }
         if(sum!=0)
            num*=sum;
    }
    return num;
}
int main()
{
    int a,b,c;
    int sum=0;
    cin>>a>>b>>c;
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
            for(int k=1;k<=c;k++)
              {
                  sum+=finddiv(i*j*k);
              }
    cout<<sum<<endl;


    return 0;
}
