#include <bits/stdc++.h>
using namespace std;
long long s;
vector <long long> v;
long long num(long long n)
{
    int c=0;
    while(n>0)
    {
        c++;
        n=n/10;
    }
    return c;
}
void backtrack(int cnt4=0,int cnt7=0,long long st=0)
{
    //cout<<st<<"  "<<cnt4<<"  "<<cnt7<<endl;
    if(st>=s&&cnt4==cnt7&&cnt4+cnt7>=num(s)&&cnt4+cnt7<=num(s)+2)
     {
         //cout<<"A1"<<endl;
         v.push_back(st);
         return;
     }
    if(cnt4+cnt7==num(s)+2)
    {
        //cout<<"A2"<<endl;
        return;
    }

    backtrack(cnt4+1,cnt7,st*10+4);
    backtrack(cnt4,cnt7+1,st*10+7);
    /*cout<<a<<"  "<<b<<endl;
    return (a>b)?a:b;*/
}
int main()
{
    cin>>s;
    backtrack();
    cout<<*min_element(v.begin(),v.end())<<endl;


    return 0;
}
