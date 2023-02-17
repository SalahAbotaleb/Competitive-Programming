#include <bits/stdc++.h>
#define ll long long
const int N=1e4+4;
using namespace std;
void pre()
{
    //ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return;
}
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
int dr8[]={1,-1,0,0,1,1,-1,-1};
int dc8[]={0,0,1,-1,1,-1,1,-1};
int findExpr();
int findComp();
int findFact();
string s;
int curr=0;
bool is_error=0;
int findExpr(){
    if(is_error)
        return -1;
    int ans=findComp();
    if(curr==s.size())
        return ans;
    if(s[curr]=='+')
    {
        curr++;
        if(curr==s.size())
            is_error=1;
        ans+=findExpr();
    }
    else{
        if(s[curr]!='*'&&s[curr]!=')')
            is_error=1;
    }
    return ans;
}
int findComp(){
    if(is_error)
        return -1;
    int ans=findFact();
    if(curr==s.size())
        return ans;
    if(s[curr]=='*')
    {
        curr++;
        if(curr==s.size())
            is_error=1;
        ans*=findComp();
    }
    else{
        if(s[curr]!='+'&&s[curr]!=')')
            is_error=1;
    }

    return ans;
};
int findFact(){
    if(is_error) {
        return -1;
    }
    if(curr==s.size())
        is_error=1;
    int ans=0,ok=0;
    while(s[curr]>='0'&&s[curr]<='9')
    {
        ok=1;
        ans=(ans*10)+(s[curr++]-'0');
    }
    if(ok)
        return ans;
    if(s[curr]=='(')
    {
        curr++;
        ans=findExpr();
        if(curr>=s.size())
            is_error=1;
        else
        {
            if(s[curr]!=')')
                is_error=1;
            curr++;
        }
    }
    else
    {
        is_error=1;
    }

    return ans;
};
int main()
{
    pre();
    int tc;
    cin>>tc;
    while(tc--)
    {
        cin>>s;
        is_error=0;
        curr=0;
        int ans=findExpr();
        if(is_error || curr!=s.size())
            cout<<"ERROR\n";
        else
            cout<<ans<<endl;
    }

    return 0;
}
