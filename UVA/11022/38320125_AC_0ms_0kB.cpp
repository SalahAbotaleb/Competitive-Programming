#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7,N=81;
int dp[N][N];
int mem[N][N];
string s;
int d;
vector<int> prefix_function (string& s,int beg,int end)
{
    vector<int>fail(end-beg+1,0);
    for(int i=beg+1,k=1;i<=end&&k<fail.size();i++,k++)
    {
        int j=fail[k-1];
        while(j>0&&s[j+beg]!=s[i])
            j=fail[j-1];
        if(s[j+beg]==s[i])
            fail[k]=j+1;
        else
            fail[k]=0;
    }
    return fail;
}
vector<int> KMP(string s,string pat)
{
    vector<int>fail= prefix_function(pat,0,1);
    vector<int>ans;
    int j=0;
    for(int i=0;i<s.size();i++)
    {
        while(j>0&&s[i]!=pat[j])
            j=fail[j-1];
        if(s[i]==pat[j])
        {
            j++;
        }
        if(j==pat.size())
        {
            ans.push_back(i-j+1);
            j=fail[j-1];
        }
    }
    return ans;
}
int solve(int i,int j)
{
    if(i>j) {
        return 1e9;
    }
    if(i==j) {
        return 1;
    }
    if(j-i==1) {
        return (s[j]==s[i]?1:2);
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int opt4=INT_MAX;
    for(int beg=i+1;beg<j;beg++) {
        opt4=min(opt4,solve(i,beg)+solve(beg+1,j));
    }
    int opt1=1+solve(i+1,j);
    int opt2=1+solve(i,j-1);
    int opt3=INT_MAX;
    int ikm=prefix_function(s,i,j).back();
    int len=(j-i+1)-ikm;
    if(ikm&&(j-i+1)%len==0)
    {
        if(i==5&&j==6)
            cin>>d;
        opt3=min({len,1+solve(i+1,i+len-1),1+solve(i,i+len-2)});
    }
    //cout<<opt1<<"  "<<opt2<<"  "<<opt3<<"  "<<opt4<<endl;
    return dp[i][j]=min({opt1,opt2,opt3,opt4});
}
void build(int i,int j)
{
    if(i>j)
        return;
    if(i==j)
    {
        cout<<s[i];
    return;
    }
    int ans= dp[i][j];
    int opt1=1+solve(i+1,j);
    int opt2=1+solve(i,j-1);
    int opt3=INT_MAX;
    int opt4=INT_MAX;
    for(int beg=i+1;beg<j;beg++) {
        opt4 = min(beg, solve(i, beg) + solve(beg + 1, j));
        if(ans==opt4)
        {
            if(beg-i==1) {
                cout << (s[beg] == s[i] ? s[i] : s[i] + s[beg]);
                return;
            }else
            build(i, beg);
            if(beg-i==1) {
                cout << (s[beg+1] == s[j] ? s[beg+1] : s[beg+1] + s[j]);
                return;
            }else
            build(beg + 1, j);
            return;
        }
    }
    int ikm=prefix_function(s,i,j).back();
    int len=(j-i+1)-ikm;
    if(ikm&&(j-i+1)%len==0)
    {
        opt3=min({len,1+solve(i+1,i+len-1),1+solve(i,i+len-2)});
    }
    if(ans==opt2)
    {
        build(i,j-1);
        cout<<s[j];

    }
    else
        if(ans==opt1)
        {
            cout<<s[i];
            build(i+1,j);
        }
        else
        {
            if(ans==len)
            {
                cout<<s.substr(i,len);
            }else if(ans==1+solve(i+1,i+len-1))
            {
                cout<<s[i];
                build(i+1,i+len-1);
            }
                else
                {if(ans==1+solve(i,i+len-2))
                build(i,i+len-2);
                cout<<s[i+len-2];
                }
        }
}
int main()
{

    while(cin>>s&&s!="*") {
    memset(dp,-1,sizeof dp);
    memset(mem,-1,sizeof dp);
    cout<<solve(0,s.size()-1)<<endl;
    }
    return 0;
}


