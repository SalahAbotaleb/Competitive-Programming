#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n&&n)
    {
        int f;
        while(cin>>f&&f) {
            queue<int> q;
            queue<int>qf;
            qf.push(f);
            q.push(1);
            for(int i=1;i<n;i++)
            {
                int x;
                cin>>x;
                qf.push(x);
                q.push(i+1);
            }
            bool ok=1;
            stack<int>s;
            while(!qf.empty())
            {
                int curr=qf.front();
                if(!q.empty())
                {
                    if(q.front()==curr)
                    {
                        q.pop();
                        qf.pop();
                        continue;
                    }
                }
                if(!s.empty())
                {
                    if(s.top()==curr)
                    {
                        s.pop();
                        qf.pop();
                        continue;
                    }
                }
                if(!q.empty())
                {
                    while(!q.empty()&&q.front()!=qf.front())
                    {
                        s.push(q.front());
                        q.pop();
                    }
                    if(!q.empty())
                    {
                        q.pop();
                        qf.pop();
                    }else{
                        break;}
                }
                if(qf.front()==curr)
                {
                    ok=0;
                    break;
                }
            }
            if(qf.empty()&&ok)
            {
                cout<<"Yes"<<endl;
            }else
                cout<<"No"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
