#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n,m;
    while(cin>>n>>m&&n)
    {
        int arr[m][3];
        int comp[n];
        for(int i=0;i<m;i++)
        {
            cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        }
        for(int i=0;i<n;i++) comp[i]=i;
        int c=0;
        do{
            bool ok=1;
            for(int i=0;i<m;i++)
            {
                int idx1=find(comp,comp+n,arr[i][0])-comp;
                int idx2=find(comp,comp+n,arr[i][1])-comp;
                if(arr[i][2]<0)
                    if(abs(idx1-idx2)<abs(arr[i][2]))
                        ok=0;
                if(arr[i][2]>0)
                        if(abs(idx1-idx2)>abs(arr[i][2]))
                            ok=0;
            }
            if(ok) c++;
        }while(next_permutation(comp,comp+n));
        cout<<c<<endl;
    }





    return 0;
}
