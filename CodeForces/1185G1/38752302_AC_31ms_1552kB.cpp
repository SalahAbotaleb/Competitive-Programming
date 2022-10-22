    #include <bits/stdc++.h>
    #define int long long
    #define ll long long
    #define el '\n'
    using namespace std;
    #define FIFO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    const ll loo = 0x3f3f3f3f3f3f3f3f;
    const int oo = 1e9, mod = 1e9 + 7;
    int n, tot;
    const int N = 1 << 16;
    int mem[N][3];
    int t[16], g[16];

    int solve( int msk, int prev, int ttime) {
        if (ttime == tot)
            return 1;
        if (ttime > tot)
            return 0;
        if (mem[msk][prev] != -1) return mem[msk][prev];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (msk & (1 << i))
                continue;
            if (g[i] != prev)
                ans = (ans % mod + solve( msk | (1 << i), g[i], ttime + t[i]) % mod) % mod;
        }
        return mem[msk][prev] = ans;
    }

    signed main() {
        memset(mem,-1,sizeof mem);
        cin >> n >> tot;
        for (int i = 0; i < n; i++) {
            cin >> t[i] >> g[i];
        }
        int ans=0;
        for(int i=0;i<n;i++)
        ans=(ans%mod+ solve( 1<<i, g[i], t[i])%mod)%mod;
        cout<<ans<<endl;
    }
