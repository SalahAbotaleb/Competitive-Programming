#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7,N=1e6+5;
vector<int> prefix_function (string s)
{
    vector<int>fail(s.size(),0);
    for(int i=1;i<s.size();i++)
    {
        int j=fail[i-1];
        while(j>0&&s[j]!=s[i])
            j=fail[j-1];
        if(s[j]==s[i])
            fail[i]=j+1;
        else
            fail[i]=0;
    }
    return fail;
}
vector<int> KMP(string s,string pat)
{
    vector<int>fail= prefix_function(pat);
    vector<int>ans;
    int j=0;
    for(int i=0;i<s.size();i++)
    {
        while(j>0&&s[i]!=pat[j])
            j=fail[j-1];
        if(s[i]==pat[j])
            j++;
        if(j==pat.size())
        {
            ans.push_back(i-j+1);
            j=fail[j-1];
        }
    }
    return ans;
}
int main()
{
    vector<string>s(3);
    for(int i=0;i<3;i++)
        cin>>s[i];
    sort(s.begin(),s.end());
    int ans=INT_MAX;
    do{
        string a=s[0];
        string b=s[1];
        string c=s[2];
        if(KMP(a,b).empty())
        {
            int val= prefix_function(b+"$"+a).back();
            a=a+b.substr(val,b.size()-min(val,(int)b.size()));
        }
        b=c;
        if(KMP(a,b).empty())
        {
            int val= prefix_function(b+"$"+a).back();
            a=a+b.substr(val,b.size()-min(val,(int)b.size()));
        }
    ans=min(ans,(int)a.size());
       // cout<<a<<endl;
    }while(next_permutation(s.begin(),s.end()));
    cout<<ans<<endl;
    return 0;
}


