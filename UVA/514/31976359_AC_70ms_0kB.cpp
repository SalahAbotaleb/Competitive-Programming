#include <bits/stdc++.h>
using namespace std;
int main()
{

    while(1)
    {
    int n;
    cin>>n;
    int f;
    while(n!=0)
    {
        queue <int> q;
        queue <int> q2;
        stack <int> s;
        cin>>f;
        if(f==0)
            break;
        q.push(f);
        for(int i=1;i<n;i++)
        {
            int x;
            cin>>x;
            q.push(x);
            q2.push(i);
        }
        q2.push(n);
        int c=n;
        for(int i=0;i<n;i++)
        {
            if(q2.front()==q.front())
            {
                q.pop();
                q2.pop();
                while(!s.empty()&&s.top()==q.front())
                {
                    q.pop();
                    s.pop();
                }

            }else
            {
                s.push(q2.front());
                q2.pop();
            }
            //cout<<"i= "<<i<<"c= "<<c<<endl;
        }
        if(q.size()+s.size()==0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
     }
     if(f==0&&n==0)
        break;
    cout<<endl;
    }

    return 0;
}
