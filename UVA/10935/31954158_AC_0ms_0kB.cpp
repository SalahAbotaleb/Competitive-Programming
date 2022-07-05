#include <bits/stdc++.h>
using namespace std;
int main()
{
    //ofstream fout;
    //fout.open("test.txt");

    int n;
    while(cin>>n,n)
    {
        queue <int> q;
        for(int i=0;i<n;i++)
            q.push(i+1);
        cout<<"Discarded cards:";
        while(q.size()!=1)
        {
            if(q.size()!=2)
                cout<<" "<<q.front()<<",";
            else
                 cout<<" "<<q.front();
            q.pop();
            q.push(q.front());
            q.pop();
        }
        cout<<endl<<"Remaining card: "<<q.front()<<endl;
    }


    return 0;
}
