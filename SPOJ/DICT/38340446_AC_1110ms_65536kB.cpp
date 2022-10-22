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
        vector<int>child;
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
            if(i!=s.size()-1)
            curr->child.push_back(idx);
        }
    }
    vector<int> get(string s)
    {
        node* curr=root;
        for(int i=0;i<s.size();i++)
        {
            if(curr->nxt[s[i]-st]==NULL)
            {
                return vector<int>();
            }
            curr=curr->nxt[s[i]-st];
        }
        return curr->child;
    }
};

int main()
{
    int tc=1;
    while(tc--) {
        trie t(26, 'a');
        int n;
        cin>>n;
        vector<string>st;
        for(int i=0;i<n;i++) {
            string s;cin>>s;
            st.push_back(s);
            t.add(s,i);
        }
        int q;
        cin>>q;
        string s;

        for(int i=0;i<q;i++)
        {
            cout<<"Case #"<<i+1<<":"<<endl;
            cin>>s;
            vector<int> ans = t.get(s);
            if(ans.empty())
            {
                cout<<"No match.\n";
            }else
            {
                set<string>out;
                for(auto it:ans) out.insert(st[it]);
                for(auto it:out)
                    cout<<it<<endl;

            }
        }
    }
    return 0;
}


