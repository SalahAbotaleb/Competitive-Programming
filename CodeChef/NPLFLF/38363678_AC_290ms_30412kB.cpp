#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7,N=1e6+5;
map<pair<int,int>,int>mp;
class trie
{
private:
    struct node{
        vector<node*>nxt;
        int cnt=0;
        int lvl=0;
        node(int _sz):nxt(vector<node*>(_sz,NULL)){}
    }*root;
    int sz;
    int st;
public:
    trie(int sz,char st)
    {
        root=new node(sz);
        this->sz=sz;
        this->st=st;
    }
    void add(string &s)
    {
        node*curr=root;
        for(int i=0;i<s.size();i++)
        {
            if(curr->nxt[s[i]-st]==NULL)
            {
                curr->nxt[s[i]-st]=new node(sz);
                curr->nxt[s[i]-st]->lvl=1+curr->lvl;
            }
            curr=curr->nxt[s[i]-st];
            curr->cnt++;
            mp[{curr->lvl,curr->cnt}]++;
        }
    }
    void remove(string &s)
    {
        node*curr=root;
        for(int i=0;i<s.size();i++)
        {
            if(curr->nxt[s[i]-st]==NULL)
            {
                return;
            }
            curr=curr->nxt[s[i]-st];
            mp[{curr->lvl,curr->cnt}]--;
            curr->cnt--;
        }
    }
};
int main()
{
    int q;
    cin>>q;
    map<int,string>v;
    trie t(26,'a');
    for(int i=0;i<q;i++)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            string s;
            cin>>s;
            reverse(s.begin(),s.end());
            v[i+1]=s;
            t.add(s);
        }
        if(n==2)
        {
            int k,l;
            cin>>k>>l;
            cout<<(mp[{l,k}]?"YES\n":"NO\n");
        }
        if(n==3)
        {
            int k;
            cin>>k;
            t.remove(v[k]);
            v[k]="";
        }
    }
    return 0;
}


