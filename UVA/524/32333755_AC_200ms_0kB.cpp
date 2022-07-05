#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> v;
//ofstream fout;
void backtrack(int val=1,int idx=0,int msk=1<<1) //2 3 5 7 11 13
{

//fout.open("test.txt");
    if(idx==n-1)
    {
        /*if(v[0]!=1)
            return;*/
        if(v[0]+v[n-1]==2 || v[0]+v[n-1]==3 || v[0]+v[n-1]==5 || v[0]+v[n-1]==7 || v[0]+v[n-1]==11 || v[0]+v[n-1]==13 || v[0]+v[n-1]==17 || v[0]+v[n-1]==19 || v[0]+v[n-1]==23 || v[0]+v[n-1]==29 || v[0]+v[n-1]==31 ||v[0]+v[n-1]==37 || v[0]+v[n-1]==41)
        {
        cout<<1;
        for(int i=1;i<n;i++) cout<<" "<<v[i];
        cout<<endl;
        }
        return;
    }
    for(auto x:{2,3,5,7,11,13,17,19,23,29,31,37,41})
    {
        if(x-val<=0||x-val>n)
            continue;
        if((1<<x-val) & ~msk)
        {
            //cout<<x-val<<endl;
            v.push_back(x-val);
            backtrack(x-val,idx+1,msk|(1<<x-val));
            /*for(auto x:v) cout<<x<<" ";
        cout<<endl;*/
            v.pop_back();
        }
    }

}
int main()
{
  // ofstream fout;
//fout.open("test.txt");
    int c=0;
    while(scanf("%d",&n)!=EOF)
    {
    if(c++) cout<<endl;
    cout<<"Case "<<c<<":"<<endl;
       v.push_back(1);
       backtrack();
       v.clear();
    }

    return 0;
}
