#include <bits/stdc++.h>
using namespace std;
string s="IEHOVA#";
int ygrid[3]={-1,0,1};
int xgrid[3]={0,-1,0};
string ans[3]={"left","forth","right"};
vector <string> res;
char mat[8][8];
int n,m,sx,sy;
int c=0;
bool valid(int x,int y)
{
   /* if(x>=0&&x<n&&y>=0&&y<m)
        cout<<"yes"<<endl;*/
    //cout<<x<<"   "<<y<<endl;
    return x>=0&&x<n&&y>=0&&y<m;
}
void dfs(int x,int y)
{
    //cout<<"x "<<x<<"  y  "<<y<<endl;
    for(int i=0;i<3;i++)
    {
        if(valid(x+xgrid[i],y+ygrid[i]) && mat[x+xgrid[i]][y+ygrid[i]]==s[c])
        {
            res.push_back(ans[i]);
            c++;
            dfs(x+xgrid[i],y+ygrid[i]);
          break;
        }
    }
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
            if(mat[i][j]=='@')
            {
                //cout<<i<<"    ...   "<<j<<endl;
                sx=i;
                sy=j;
            }
        }
    dfs(sx,sy);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" \n"[i==res.size()-1];
    res.clear();
    c=0;
    }
    return 0;
}
