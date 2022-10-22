#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N=1001;
pair<int,int> mem[1001][501];
int l,n,C;
int t[1001];
pair<int,int> solve(int idx,int rem)
{
    if(idx==n)
        return {0,(rem==0?0:(rem<=10)?-C:(rem-10)*(rem-10))};
    if(mem[idx][rem].first!=-1) return mem[idx][rem];
    pair<int,int> opt1={1e9,1e9},opt2={1e9,1e9},opt3={1e9,1e9};
    if(rem-t[idx]>=0)//able to take
    {
        opt1=solve(idx+1,rem-t[idx]);
    }
    opt2=solve(idx+1,l-t[idx]);
    opt2.first+=1;
    opt2.second+=(rem==0?0:(rem<=10)?-C:(rem-10)*(rem-10));
    //cout<<opt1.first<<"  "<<opt1.second<<"  <--->  "<<opt2.first<<"  "<<opt2.second<<"  "<<rem<<endl;
    if(opt1.first==opt2.first)
        return mem[idx][rem]={opt1.first,min(opt1.second,opt2.second)};
    else
        if(opt1.first<opt2.first)
        return mem[idx][rem]=opt1;
        else
        return mem[idx][rem]=opt2;
}
/*void build(int idx,int rem)
{
    if(idx==n)
        return;
    pair<int,int> opt1={1e9,1e9},opt2={1e9,1e9},opt3={1e9,1e9};
    if(rem-t[idx]>=0)//able to take
    {
        opt1=solve(idx+1,rem-t[idx]);
    }
    opt2=solve(idx+1,l-t[idx]);
    opt2.first+=1;
    opt2.second+=(rem==0?0:(rem<=10)?-C:(rem-10)*(rem-10));
    //cout<<opt1.first<<"  "<<opt1.second<<"  <--->  "<<opt2.first<<"  "<<opt2.second<<"  "<<rem<<endl;
    cout<<rem<<endl;
    if(opt1==mem[idx][rem])
    {
        cout<<"continue: "<<t[idx]<<"  "<<0<<endl;
        build(idx+1,rem-t[idx]);
    }
    else
    {
        cout<<"stop: "<<t[idx]<<"  "<<(rem==0?0:(rem<=10)?-C:(rem-10)*(rem-10))<<endl;
        build(idx+1,l-t[idx]);
    }
}*/
int main()
{
    int tc=0;
    while(cin>>n&&n)
    {
        if(tc)
            cout<<endl;
        cin>>l>>C;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=l;j++)
            {
                mem[i][j]={-1,-1};
            }
        }
        for(int i=0;i<n;i++) cin>>t[i];
        auto ans=solve(0,0);
        //build(0,0);
        cout<<"Case "<<++tc<<":"<<endl;
        cout<<"Minimum number of lectures: "<<ans.first<<endl;
        cout<<"Total dissatisfaction index: "<<ans.second<<endl;
    }
    return 0;
}
