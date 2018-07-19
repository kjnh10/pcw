// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

const int N = (int) 2e3 + 3, mod = (int) 1e9 + 7;
#define int long long
void sadd(int &x, int y) { x += y; x %= mod; }
int dp[N], odp[N], comb[N][N];
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j <= i; ++j)
            comb[i][j] = (i == j || j == 0)? 1: (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
    dp[0] = 1;
    for (int x = a; x <= b; ++x) {
        memcpy(odp, dp, sizeof dp);
        memset(dp, 0, sizeof dp);
        for (int sz = 0; sz <= n; ++sz) {
            int z = 1;
            for (int pick = 0; sz + pick * x <= n && pick <= d; ++pick) {
                if (pick >= c) {
                    sadd(dp[sz + pick * x], odp[sz] * z % mod * comb[n - sz][pick * x] % mod);
                }
                if ((pick + 1) * x - 1 < N)
                    z = z * comb[(pick + 1) * x - 1][x - 1] % mod;
            }
        }
        for (int sz = 0; sz <= n; ++sz) {
            sadd(dp[sz], odp[sz]);
        }
    }
    cout << dp[n] << endl;
}