#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    long long presum=0;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=presum)
            c++;
        else
        {
            auto idx=lower_bound(arr.begin()+i,arr.end(),presum);
            if(idx!=arr.end())
            {
                int ii=idx-arr.begin();
                //cout<<i<<" "<<ii<<endl;
                c++;
                swap(arr[i],arr[ii]);
            }
        }
        presum+=arr[i];
    }
    cout<<c<<endl;

    return 0;
}
