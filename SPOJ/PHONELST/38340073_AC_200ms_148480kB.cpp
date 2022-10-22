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
        bool isleaf=1;
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
    bool add(string &s)
    {
        node* curr=root;
        for(int i=0;i<s.size();i++)
        {
            if(curr->nxt[s[i]-st]==NULL)
            {
                curr->nxt[s[i]-st]=new node(sz);
            }
            else
            {
                if(curr->nxt[s[i]-st]->isleaf)
                    return 0;
            }
            curr=curr->nxt[s[i]-st];
            curr->cnt++;
            if(i!=s.size()-1)
                curr->isleaf=0;
            if(i==s.size()-1)
                if(curr->cnt!=1)
                    return 0;
        }
        return 1;
    }
};

int main()
{
    int tc;
    cin>>tc;
    while(tc--) {
        trie t(10, '0');
        int n;
        cin>>n;
        bool ok=1;
        for(int i=0;i<n;i++) {
            string s;cin>>s;
            ok&=t.add(s);
        }
        cout<<(ok?"YES\n":"NO\n");
    }
    return 0;
}


