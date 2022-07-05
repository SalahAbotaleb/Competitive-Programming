#include <bits/stdc++.h>
using namespace std;
int main()
{
    //ofstream fout;
    //fout.open("test.txt");
    int n;
    while(~scanf("%d",&n))
    {
        stack <int> s;
        queue <int> q;
        priority_queue <int> pq;
        bool ok=0;
        int c[3]={0};
        int t=0;
        for(int i=0;i<n;i++)
        {
            int opr;
            int res;
            cin>>opr>>res;
            if(opr==1)
            {
                s.push(res);
                q.push(res);
                pq.push(res);
            }
            else
            {
                if (s.empty())
                {
                    ok=1;
                  continue;
                }
                t++;
                if(s.top()==res)
                    c[0]++;
                if(q.front()==res)
                    c[1]++;
                if(pq.top()==res)
                    c[2]++;
                s.pop();
                q.pop();
                pq.pop();
            }
        }
        if(ok)
            cout<<"impossible"<<endl;
        else
        if((c[0]==t&&c[1]==t) || (c[1]==t&&c[2]==t) ||  (c[0]==t&&c[2]==t) )
            cout<<"not sure"<<endl;
        else
            if(c[0]!=t&&c[1]!=t&&c[2]!=t)
                cout<<"impossible"<<endl;
        else
            if(c[0]==t)
                cout<<"stack"<<endl;
        else
            if(c[1]==t)
                cout<<"queue"<<endl;
        else
            if(c[2]==t)
                cout<<"priority queue"<<endl;

    }


    return 0;
}
