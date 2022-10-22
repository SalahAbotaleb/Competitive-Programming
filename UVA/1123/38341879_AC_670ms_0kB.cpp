#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7,N=1e6+5;
unordered_map<int,int>mp;
int thr;
int ans;
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
    void add(string &s,int beg,int end)
    {
        node* curr=root;
        for(int i=beg;i<=end;i++)
        {
            if(curr->nxt[s[i]-st]==NULL)
            {
                curr->nxt[s[i]-st]=new node(sz);
            }
            else
            {
                if(i==end)
                    return;
            }
            curr=curr->nxt[s[i]-st];
            mp[s[i]-st]++;
            curr->cnt=mp.size();
        }
        if(curr->cnt<=thr)
            ans++;
    }
    vector<int> get(string &s)
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
    int tc;
    cin>>tc;
    while(tc--) {
        trie t(26, 'a');
        int n;
        ans=0;
        string s;
        cin>>n>>thr;
        cin>>s;
        for(int i=0;i<=s.size()-n;i++)
        {
            mp.clear();
            t.add(s,i,i+n-1);
        }
        cout<<ans<<endl;
        if(tc)
            cout<<endl;
    }
    return 0;
}


