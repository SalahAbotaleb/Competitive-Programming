#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7,N=1e6+5;
class trie
{
private:
    struct node{
        vector<node*>nxt={ };
        int cnt=0;
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
    void add(string &s,int idx)
    {
        node* curr=root;
        for(int i=0;i<s.size();i++)
        {
            if(curr->nxt[s[i]-st]==NULL)
            {
                curr->nxt[s[i]-st]=new node(sz);
            }
            curr=curr->nxt[s[i]-st];
            curr->cnt++;
        }
    }
    int get(string s)
    {
        node* curr=root;
        for(int i=0;i<s.size();i++)
        {
            if(curr->nxt[s[i]-st]==NULL)
            {
                return 0;
            }
            curr=curr->nxt[s[i]-st];
        }
        return curr->cnt;
    }
};

int main()
{
    int tc=1;
    while(tc--) {
        trie t(26, 'a');
        int n;
        cin>>n;
        int q;
        cin>>q;
        vector<string>st;
        for(int i=0;i<n;i++) {
            string s;cin>>s;
            st.push_back(s);
            t.add(s,i);
        }
        string s;

        for(int i=0;i<q;i++)
        {
            cin>>s;
            int ans = t.get(s);
            cout<<ans<<endl;
        }
    }
    return 0;
}


