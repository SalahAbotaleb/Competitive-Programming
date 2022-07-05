#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> m;
    vector <int> n;
    int cm,cn;
    scanf("%d%d",&cn,&cm);
    for(int i=0;i<cn;i++)
    {
        int x;
        scanf("%d",&x);
        n.push_back(x);
    }
    for(int i=0;i<cm;i++)
    {
        int x;
        scanf("%d",&x);
        m.push_back(x);
    }
    sort(n.begin(),n.end());
    int arr[cm]={0};
    for(int i=0;i<cm;i++)
    {
        int pos=upper_bound(n.begin(),n.end(),m[i])-1-n.begin();
        if(pos!=-1)
            arr[i]=pos+1;
    }
    for(int i=0;i<cm;i++) cout<<arr[i]<<" \n"[i==cm-1];
    return 0;
}
