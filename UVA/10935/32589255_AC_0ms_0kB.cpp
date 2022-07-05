#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n,n)
    {
        queue <int> q;
        for(int i=0;i<n;i++)
        {
            q.push(i+1);
        }
        int C=0;
        printf("Discarded cards:");
        while(q.size()>=2)
        {
            if(C==0) cout<<" ";
            if(C++) cout<<", ";
            cout<<q.front();
            q.pop();
            q.push(q.front());
            q.pop();
        }
        printf("\nRemaining card: %d\n",q.front());
    }





    return 0;
}

