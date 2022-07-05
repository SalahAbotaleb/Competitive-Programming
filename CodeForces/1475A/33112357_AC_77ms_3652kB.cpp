#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e7;
ll n;
int main()
{

    int tc;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        while(n%2==0)
            n/=2;
        cout<<(n>1?"YES":"NO")<<endl;
    }
    return 0;
}
