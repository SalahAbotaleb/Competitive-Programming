#include <bits/stdc++.h>
using namespace std;
int t,n;
const int N=12;
int arr[N];
set <vector<int> > st;
void backtrack(int idx=0,int sum=0,int msk=0)
{
    //cout<<idx<<"  "<<sum<<endl;
    if(sum==t)
    {
        int cnt=0;
        vector <int> v;
        for(int i=0;i<n;i++)
        {
            if((1<<i)&msk)

            {
                v.push_back(arr[i]);
            }
        }
        if(st.find(v)==st.end())
            st.insert(v);
        else
            return;
        for(int i=0;i<n;i++)
        {
            if((1<<i)&msk)

            {
                if(cnt++) cout<<"+";
                cout<<arr[i];
            }
        }
        cout<<endl;
    }
    if(sum>t)
        return;
    if(idx==n)
        return;
    backtrack(idx+1,sum+arr[idx],msk|(1<<idx));
    backtrack(idx+1,sum,msk);

}
int main()
{
    while(cin>>t>>n&&t&&n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<"Sums of "<<t<<":"<<endl;
        backtrack();
        if(st.empty())
            cout<<"NONE"<<endl;
        st.clear();
    }


    return 0;
}
