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
int main()
{
    string s;
    int n;
    int tc=0;
    int ccc;
    cin>>ccc;
    while(ccc--) {
        cin>>n>>s;
        vector<int> fail = prefix_function(s);
        cout<<"Test case #"<<++tc<<endl;
        for(int i=1;i<s.size();i++)
        {
            int len=(i+1-fail[i]);
            if(fail[i]&&(i+1)%len==0)
                cout<<i+1<<" "<<(i+1)/len<<endl;
        }
        cout<<endl;
    }
    return 0;
}


