#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack <int> s;
    int n;
    cin>>n;
    while(n--)
    {
        int op,num;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&num);
            s.push(num);
        }
        if(!s.empty()&&op==2)
        {
            s.pop();

        }

        if(op==3)
        {
            if(s.empty())
            {
                printf("Empty!\n");
            }else
            {
                printf("%d\n",s.top());
            }
        }
    }

//sasa
    return 0;
}
