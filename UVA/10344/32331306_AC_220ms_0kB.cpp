#include <bits/stdc++.h>
using namespace std;
const int N=5;
int arr[N];
bool found=0;
void backtrack(int idx=0,int sum=0)
{
    if(sum==23&&idx==5)
    {
        found=1;
        return;
    }
    if(idx==5)
        return;
    if(idx==0)
        backtrack(idx+1,arr[idx]);
    else
    {
        backtrack(idx+1,sum-arr[idx]);
        backtrack(idx+1,sum+arr[idx]);
        backtrack(idx+1,sum*arr[idx]);
    }
}
int main()
{
    while(cin>>arr[0],arr[0])
    {
        for(int i=1;i<5;++i)
        {
            cin>>arr[i];
        }
        sort(arr,arr+5);
        do
        {
            backtrack();
        }while(next_permutation(arr,arr+5));
        if(found)
            cout<<"Possible"<<endl;
        else
            cout<<"Impossible"<<endl;
        found=0;
    }



    return 0;
}
