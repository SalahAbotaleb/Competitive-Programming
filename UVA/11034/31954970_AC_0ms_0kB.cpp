#include <bits/stdc++.h>
using namespace std;
int main()
{
    //ofstream fout;
    //fout.open("test.txt");
    int n;
    cin>>n;
    while(n--)
    {
     int c=0;
     char pos='l';
     deque <int> l;
     deque <int> r;
     int len,m;
     cin>>len>>m;
     len*=100;
     for(int i=0;i<m;i++)
     {
         string s;
         int t;
         cin>>t>>s;
         if (s[0]=='l')
            l.push_back(t);
         else
            r.push_back(t);
     }
    while(l.size()+r.size())
    {
        if(pos=='l')
        {
            pos='r';
            c++;
            int siz=len;
            int curr=0;
            while(1)
            {
                if (l.size()==0)
                    break;
                if(curr+l.front()<=siz)
                {
                    curr+=l.front();
                    l.pop_front();
                }
                else
                    break;
            }
            //cout<<"curr: left: "<<curr<<endl;
        }
        if(l.size()+r.size()==0)
            break;
        if(pos=='r')
        {
            c++;
            pos='l';
            int siz=len;
            int curr=0;
            while(1)
            {
                if(r.size()==0)
                    break;
                if(curr+r.front()<=siz)
                {
                    curr+=r.front();
                    r.pop_front();
                }
                else
                    break;
            }
            //cout<<"curr: right: "<<curr<<endl;
        }
    }
    cout<<c<<endl;
    }

    return 0;
}
