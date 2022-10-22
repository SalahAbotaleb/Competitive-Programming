#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
void init() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
}
int main()
{
    init();
    ll mat[26][26];
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
        {
            mat[i][j]=INT_MAX;
            if(i==j)
                mat[i][j]=0;
        }
    string s1;
    string s2;
    cin>>s1>>s2;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char a,b;
        ll c;
        cin>>a>>b>>c;
        mat[a-'a'][b-'a']=min(c,mat[a-'a'][b-'a']);
    }
    for(int k=0;k<26;k++)
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
    if(s1.size()!=s2.size())
    {
        return cout<<-1,0;
    }
    ll res=0;
    string ff="";
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]==s2[i]) {
            ff+=s1[i];
            continue;
        }ll ans=INT_MAX;
        int idx=0;
        for(int j=0;j<26;j++)
        {
            if(mat[s1[i]-'a'][j]+mat[s2[i]-'a'][j]<ans)
            {
                ans=mat[s1[i]-'a'][j]+mat[s2[i]-'a'][j];
                idx=j;
            }
        }
        if(ans==INT_MAX)
            return cout<<-1,0;
        res+=ans;
        ff+=('a'+idx);
    }
    cout<<res<<endl;
    cout<<ff<<endl;
    return 0;
}
