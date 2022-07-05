#include <bits/stdc++.h>
using namespace std;
int n;
char arr[15][15];
int rd,ld,row;
int cnt;
void backtrack(int col=0)
{
    if(col==n)
    {
        cnt++;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!(row & (1<<i)) && !(rd &(1<<(i+col))) && !(ld & (1<<(i-col+n-1))) && arr[i][col]!='*')
        {
            row|=(1<<i);
            rd|=(1<<(i+col));
            ld|=(1<<(i-col+n-1));
            backtrack(col+1);
            row&=~(1<<i);
            rd&=~(1<<(i+col));
            ld&=~(1<<(i-col+n-1));
        }
    }
}
int main()
{
    int c=1;

    while(cin>>n&&n)
    {
    rd=ld=row=0;
    cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    backtrack();
    cout<<"Case "<<c++<<": "<<cnt<<endl;
    }

    return 0;
}
