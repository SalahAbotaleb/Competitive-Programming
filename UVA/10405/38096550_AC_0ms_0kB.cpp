#include <bits/stdc++.h>
#define ll long long
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
using namespace std;
int mem[1000][1000];
string s1;
string s2;
int solve(int i,int j)
{
    if(i==s1.size()||j==s2.size())
        return 0;
    if(mem[i][j]!=-1) return mem[i][j];
    int opt3=0;

    if(s1[i]==s2[j]) return mem[i][j]=opt3=1+solve(i+1,j+1);
    int opt1=solve(i,j+1);
    int opt2=solve(i+1,j);
    return mem[i][j]=max({opt1,opt2,opt3});
}
int main()
{
    while(getline(cin,s1)&& getline(cin,s2))
    {
        memset(mem,-1,sizeof mem);
        cout<<solve(0,0)<<endl;
    }
    return 0;
}


