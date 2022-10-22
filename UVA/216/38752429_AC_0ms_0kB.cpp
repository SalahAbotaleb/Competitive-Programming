#include <bits/stdc++.h>

#define ll long long
#define el '\n'
using namespace std;
#define FIFO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const ll loo = 0x3f3f3f3f3f3f3f3f;
const int oo = 1e9, mod = 1e9 + 7;
int n, tot;
const int N = 1 << 9;
double mem[N][8];
int x[8], y[8];
double diff = 1e-9;

double solve(int msk, int prev) {
    if (msk == (1 << n) - 1)
        return 0;
    if (mem[msk][prev] != -1) return mem[msk][prev];
    double ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (msk & (1 << i))
            continue;
        ans = min(ans, sqrt((x[prev] - x[i]) * (x[prev] - x[i]) + (y[prev] - y[i]) * (y[prev] - y[i])) +
                       solve(msk | (1 << i), i));
    }
    return mem[msk][prev] = ans;
}

void build(int msk, int prev) {
    if (msk == (1 << n) - 1)
        return;
    for (int i = 0; i < n; i++) {
        if (msk & (1 << i))
            continue;
        double ans = sqrt((x[prev] - x[i]) * (x[prev] - x[i]) + (y[prev] - y[i]) * (y[prev] - y[i])) +
                     solve(msk | (1 << i), i);
        if (ans == mem[msk][prev]) {
            cout << "Cable requirement to connect (" << x[prev] << "," << y[prev] << ") to (" << x[i] << "," << y[i]
                 << ") is " << fixed << setprecision(2)
                 << sqrt((x[prev] - x[i]) * (x[prev] - x[i]) + (y[prev] - y[i]) * (y[prev] - y[i])) + 16 << " feet."
                 << endl;
            build(msk | (1 << i), i);
            return;
        }
    }
}

int main() {
    int tc=0;
    while (cin >> n && n) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < n; j++)
                mem[i][j] = -1;
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        cout<<"**********************************************************"<<endl;
        cout<<"Network #"<<++tc<<endl;
        double ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            {
                ans = min(ans, solve(1 << i, i));
            }
        }
        for (int i = 0; i < n; i++) {
            {
                if (solve(1 << i, i) == ans) {
                    build(1 << i, i);
                    break;
                }
            }
        }
        cout << fixed << setprecision(2) << "Number of feet of cable required is " << ans + 16 * (n - 1) << "." << endl;
    }
}
