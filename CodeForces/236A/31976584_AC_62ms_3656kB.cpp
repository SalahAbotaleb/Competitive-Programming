#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,u;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(!u.empty())
        {
            bool found=0;
            for(int j=0;j<u.size();j++)
            {
                if(u[j]==s[i])
                {
                    found=1;
                    break;
                }
            }
            if(!found)
                u+=s[i];

        }else
        u=s[i];


    }
    if(u.size()%2==0)
        cout<<"CHAT WITH HER!"<<endl;
    else
        cout<<"IGNORE HIM!"<<endl;
//sa
    return 0;
}
