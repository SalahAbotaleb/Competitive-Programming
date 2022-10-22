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
    int tc;
    cin>>tc;
    while(tc--)
    {
        memset(fail,0,sizeof fail);
        string s,pat;
        cin>>s>>pat;
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
            cout<<"Not Found\n";
        else {
            cout << v.size() << endl;
            for (auto it: v) cout << it+1 << " ";
            cout<<endl;
        }cout<<endl;
    }
    return 0;
}


