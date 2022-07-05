#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c=0;
    string s;
    while(cin>>s && s[0]!='-')
    {
       int step=0;
       vector <bool> v(2000,0);
       for(int i=0;i<s.size();i++)
       {
           if(v[i]==1)
            continue;
           if (s[i]=='{')
            {for (int j=i+1;j<s.size();j++)
            {
                if(v[j]==1)
                    continue;
               if(s[j]=='}')
                    {
                        v[i]=1;
                        v[j]=1;
                        break;
                    }
            }
            }
       }
       for(int i=0;i<s.size();i++)
        {
            if(v[i]==1)
                continue;
            int idxj;
            for(int j=i+1;j<s.size();j++)
            {
                if(v[j]==0)
                {
                    idxj=j;
                    v[j]=1;
                    break;
                }
            }
            if ((s[i]=='{'&&s[idxj]=='{')||(s[i]=='}'&&s[idxj]=='}'))
                    step++;
                if(s[i]=='}'&&s[idxj]=='{')
                    step+=2;

        }
    /*for(int i=0;i<s.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;*/
       printf("%d. %d\n",++c,step);
    }
    return 0;
}
