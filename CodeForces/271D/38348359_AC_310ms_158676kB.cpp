#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll loo= 0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7,N=1e6+5;
int arr[26];
int ans=0;
int n;
class trie
{
private:
    struct node{
        vector<node*>nxt={ };
        int cnt=0;
        int cnt2=0;
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
    void add(string &s,int beg,int stop)
    {
        node* curr=root;
        for(int i=beg;i<=stop;i++)
        {
            if(curr->nxt[s[i]-st]==NULL)
            {
                curr->nxt[s[i]-st]=new node(sz);
            }
            else
            {
                curr->nxt[s[i]-st]->cnt=0;
            }
            curr->nxt[s[i]-st]->cnt+=curr->cnt;
            if(arr[s[i]-'a']==0)
                curr->nxt[s[i]-st]->cnt+=1;
            curr=curr->nxt[s[i]-st];
            curr->cnt2++;
            if(curr->cnt<=n&&curr->cnt2==1)
            {
               // cout<<beg<<"  "<<stop<<endl;
                ans++;
            }
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
    string s;
    cin>>s;
    string tmp;
    cin>>tmp;
    for(int i=0;i<26;i++)
        arr[i]=tmp[i]-'0';
    cin>>n;
    trie t(26,'a');
    int cc=0;
    for(int i=0;i<s.size();i++)
    {
            t.add(s,i,s.size()-1);
    }
    cout<<ans<<endl;

    return 0;
}


