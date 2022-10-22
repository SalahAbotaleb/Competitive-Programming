#include <bits/stdc++.h>

#define ll long long
#define el '\n'
using namespace std;
#define FIFO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int N = 10;
int dis[101][101][16];
char grid[101][101];
int r, c;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool valid(int x, int y) {
    return x > -1 && x < r && y > -1 && y < c && grid[x][y] != '#';
}

void bfs(int srcx, int srcy) {
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            for (int k = 0; k < 16; k++)
                dis[i][j][k]= 1e9;
    queue<pair<pair<int, int>, int>> q;
    dis[srcx][srcy][0] = 0;
    q.push({{srcx, srcy}, 0});
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int idx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nidx = idx;
            if (!valid(nx, ny))
                continue;
            if (grid[nx][ny] == 'b')
                nidx |= (1 << 0);
            if (grid[nx][ny] == 'y')
                nidx |= (1 << 1);
            if (grid[nx][ny] == 'r')
                nidx |= (1 << 2);
            if (grid[nx][ny] == 'g')
                nidx |= (1 << 3);
            bool ok = 0;
            if (grid[nx][ny] == 'B')
                if ((nidx) & (1 << 0))
                    ok = 1;
            if (grid[nx][ny] == 'Y')
                if ((nidx) & (1 << 1))
                    ok = 1;
            if (grid[nx][ny] == 'R')
                if ((nidx) & (1 << 2))
                    ok = 1;
            if (grid[nx][ny] == 'G')
                if ((nidx) & (1 << 3))
                    ok = 1;
            if ((grid[nx][ny] == 'B' || grid[nx][ny] == 'Y' || grid[nx][ny] == 'R' || grid[nx][ny] == 'G')&&!ok)
                continue;
            if (dis[x][y][idx] + 1 < dis[nx][ny][nidx]) {
                dis[nx][ny][nidx] = dis[x][y][idx] + 1;
                q.push({{nx,ny},nidx});
            }
        }
    }
}

int main() {
    while (cin >> r >> c && r && c) {
        int sx,sy,ex=-1,ey=-1;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            {
                cin>>grid[i][j];
                if(grid[i][j]=='*')
                    sx=i,sy=j;
                if(grid[i][j]=='X')
                    ex=i,ey=j;
            }
        //cout<<ex<<"  ---  "<<ey<<endl;
        if(ex==-1&&ey==-1)
        {
            cout<<"The poor student is trapped!"<<el;
            continue;
        }
        bfs(sx,sy);
        int mn=1e9;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(grid[i][j]=='X')
                mn=min(mn,*min_element(dis[i][j],dis[i][j]+16));
        if(mn==1e9)
            cout<<"The poor student is trapped!"<<el;
        else
            cout<<"Escape possible in "<<mn<<" steps."<<el;
    }
}