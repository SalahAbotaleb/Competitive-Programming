#include <bits/stdc++.h>
using namespace std;
const int N=32;
int arr[N];
int n,m;
int bestmsk,bestsum;
void backtrack (int idx,int msk,int sum)
{
//cout<<idx<<"  "<<sum<<endl;
 if(sum>m)
        return;

 if(sum>bestsum)
 {
     bestsum=sum;
     bestmsk=msk;
 }
 if(idx==n)
        return;
 backtrack(idx+1,msk,sum);
 backtrack(idx+1,msk|(1<<idx),sum+arr[idx]);
}
int main()
{
    while(cin>>m>>n)
    {
        for(int i=0;i<n;i++) scanf("%d",arr+i);
        bestsum=bestmsk=0;
        backtrack(0,0,0);
        for(int i=0;i<n;i++)
        {
            if(bestmsk&(1<<i))
                cout<<arr[i]<<" ";
        }
        cout<<"sum:"<<bestsum<<endl;
    }

    return 0;
}
