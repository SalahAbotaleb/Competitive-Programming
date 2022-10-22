#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7,N=1e6+5;
int fail[N];
void KMP (string s)
{
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
}
int main()
{
    string s,pat;
    int n;
    while(cin>>n)
    {
        cin>>pat>>s;
        memset(fail,0,sizeof fail);
        KMP(pat);
        int j=0;
        vector<int>v;
        for(int i=0;i<s.size();i++)
        {
            while(j>0&&s[i]!=pat[j])
                j=fail[j-1];
            if(s[i]==pat[j])
                j++;
            if(j==pat.size()) {
                v.push_back(i-j+ 1);
                j=fail[j-1];
            }
        }
        if(v.empty())
            cout<<"\n";
        else {
            for (auto it: v) cout << it << endl;
        }cout<<endl;
    }
    return 0;
}


