#include <bits/stdc++.h>
using namespace std;
bool check(int arr[],int per[],int n)
{
    bool isfound=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=per[i])
        {
            isfound=0;
            break;
        }
    }
    return isfound;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    int b[n];
    int f,s;
    int per[n];
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int i=0;i<n;i++) scanf("%d",b+i);
    for(int i=0;i<n;i++) per[i]=i+1;
    int c=0;
    do
    {
        c++;
        if(check(a,per,n))
            f=c;
        if(check(b,per,n))
            s=c;
    }while(next_permutation(per,per+n));
    cout<<abs(f-s)<<endl;

    return 0;
}
