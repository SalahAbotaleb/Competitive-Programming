#include <bits/stdc++.h>
#include <numeric>
using namespace std;
int main()
{
    int n;
    int c=0;
    cin>>n;
    while(n--)
    {
        int arr[7];
        char grade;
        for(int i=0;i<7;i++) scanf("%d",arr+i);
        sort(arr+4,arr+7,greater <int>());
        int mark=accumulate(arr,arr+4,0)+(arr[4]+arr[5])/2;
        switch (mark)
        {
            case 90 ... 100: grade='A'; break;
            case 80 ... 89: grade='B'; break;
            case 70 ... 79 : grade='C'; break;
            case 60 ... 69: grade='D'; break;
            default : grade='F';
        }


        printf("Case %d: %c\n",++c,grade);

    }



    return 0;
}
