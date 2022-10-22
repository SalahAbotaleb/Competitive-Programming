#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7,N=1e6+5;
unordered_map<string,int>mp;
class trie
{
private:
    struct node{
        vector<node*>nxt={ };
        int cnt=0;
        string ss="";
        int mx=0;
        node(int _sz):nxt(vector<node*>(_sz,NULL)){ };
    }*root;
    int sz;
    char st;
public:
    trie(int sz,char st)
    {
        this->sz=sz;
        this->st=st;
        root=new node(sz);
    }
    void add(string &s)
    {
        node* curr=root;
        for(int i=0;i<s.size();i++)
        {
            if(curr->nxt[s[i]-st]==NULL)
            {
               curr->nxt[s[i]-st]=new node(sz);
                curr->nxt[s[i]-st]->ss=s;
                curr->nxt[s[i]-st]->mx=mp[s];
            }
            else
            {
                if(mp[s]>curr->nxt[s[i]-st]->mx)
                {
                    curr->nxt[s[i]-st]->mx=mp[s];
                    curr->nxt[s[i]-st]->ss=s;
                }
                if(mp[s]==curr->nxt[s[i]-st]->mx&&s<curr->nxt[s[i]-st]->ss)
                {
                    curr->nxt[s[i]-st]->mx=mp[s];
                    curr->nxt[s[i]-st]->ss=s;
                }
            }
            curr=curr->nxt[s[i]-st];
        }
    }
    pair<string,int> get(string &s)
    {
        node* curr=root;
        for(int i=0;i<s.size();i++)
        {
            if(curr->nxt[s[i]-st]==NULL)
            {
                return {"",-1};
            }
            curr=curr->nxt[s[i]-st];
        }
        return {curr->ss,curr->mx};
    }
};

int main()
{
    int n;
    cin>>n;
    trie t(26,'a');
    vector<string>gg;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        gg.push_back(s);
        mp[s]++;
    }
    for(int i=0;i<n;i++)
    t.add(gg[i]);
    int q;
    cin>>q;
    while(q--)
    {
        string s;
        cin>>s;
        auto it=t.get(s);
        if(it.second==-1)
            cout<<-1<<endl;
        else
            cout<<it.first<<" "<<it.second<<endl;
    }

    return 0;
}


