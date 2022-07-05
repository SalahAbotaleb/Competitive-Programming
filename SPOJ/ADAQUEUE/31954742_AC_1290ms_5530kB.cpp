#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,c;
    cin>>n;
    c=n;
    deque <int> dq;
    bool flag=1;
    while(n--)
    {
        string s;int n;
        cin>>s;
        if(dq.size()==0&&(s=="back"||s=="front"))
        {
            cout<<"No job for Ada?"<<endl;
            continue;
        }
        if((s=="back"&&flag==1) || (s=="front"&&flag==0))
        {
            cout<<dq.back()<<endl;
            dq.pop_back();
        }
        if((s=="front"&&flag==1) || (s=="back"&&flag==0))
        {
            cout<<dq.front()<<endl;
            dq.pop_front();
        }
        if((s=="push_back"&&flag==1) || (s=="toFront"&&flag==0))
        {
            cin>>n;
            dq.push_back(n);
        }
        if((s=="toFront"&&flag==1) || (s=="push_back"&&flag==0) )
        {
            cin>>n;
            dq.push_front(n);
        }
        if(dq.size()!=0&&s=="reverse")
        {
           if (flag==1)
                flag=0;
           else
                flag=1;
          
        }

    }



    return 0;
}
