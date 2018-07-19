#include "bits/stdc++.h"
using namespace std;
#define OUT(x) cout << #x << " = " << x << endl
#define rep(i, n)             for (int (i) = 0; (i) < (int)(n); (i)++)
#define rer(i, l, r)          for (int (i) = (int)(l); (i) <= (int)(r); (i)++)
#define reu(i, l, r)          for (int (i) = (int)(l); (i) < (int)(r); (i)++)
#define all(x)                (x).begin(), (x).end()
#define rall(x)               (x).rbegin(), (x).rend()
template<typename T> void pv(T a, T b) { for (T i = a; i != b; i ++) cout << *i << " "; cout << endl; }
template<typename T, typename U> inline void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if (x < y) x = y; }
int in() { int x; scanf("%d", &x); return x; }
long long lin() { long long x; scanf("%lld", &x); return x; }

static const int MOD = 1000000007;
#define int long long

//long long extgcd(long long a, long long b, long long& x, long long& y) {
//        long long d = a;
//        if (b != 0) {
//                d = extgcd(b, a % b, y, x);
//                y -= (a / b) * x;
//        } else {
//                x = 1;
//                y = 0;
//        }
//        return d;
//}
//
//long long inv(long long a) {
//        long long x, y;
//        extgcd(a, MOD, x, y);
//        return (x % MOD + MOD) % MOD;
//}

long long inv(long long x) {
        for (long long y = 1;;y += MOD) if (y % x == 0) return y / x;
}

long long nCr(long long n, long long r) {
        //if (n < r) return 0;
        if (n - r < r) r = n - r;
        long long ret = 1;
        rep(i, r) {
                ret = ret * n % MOD;
                n --;
                ret = ret * inv(i + 1) % MOD;
        }
        return ret;
}

signed main() { 
        int n, m;
        cin >> n >> m;
        if (n < 0) n = -n;
        int ans = 1;
        for (int i = 2; i * i <= n; i ++) {
                if (n % i == 0) {
                        int cnt = 0;
                        while (n % i == 0) {
                                n /= i;
                                cnt ++;
                        }
                        ans = ans * nCr(m + cnt - 1, cnt) % MOD;
                }
        }
        if (n > 1) ans = ans * nCr(m + 1 - 1, 1) % MOD;
        rep(i, m - 1) ans = ans * 2 % MOD;
        cout << ans << endl;
        return 0;
}               

