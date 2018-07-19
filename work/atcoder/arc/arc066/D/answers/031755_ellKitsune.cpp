#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;

LL n;
int p3[61];

map<pair<LL, int>, int> save;

int solve(LL n, int pos) {
    pair<LL, int> p = mp(n, pos);
    auto it = save.find(p);
    if (it != save.end()) {
        return it->second;
    }
    if (pos == 0) {
        return save[p] = n + 1;
    }
    LL sum = 0;
    forn(i, pos) {
        sum += 2ll << i;
    }
    int ans = 0;
    for (int i = 0; i <= 2; ++i) {
        LL nn = n - ((LL)i << pos);
        if (nn >= sum) {
            ans += p3[pos];
            if (ans >= MOD) {
                ans -= MOD;
            }
        } else if (nn >= 0) {
            ans += solve(nn, pos - 1);
            if (ans >= MOD) {
                ans -= MOD;
            }
        }
    }
    return save[p] = ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    p3[0] = 1;
    for (int i = 1; i <= 60; ++i) {
        p3[i] = 3ll * p3[i - 1] % MOD;
    }
    cin >> n;
    cout << solve(n, 60) << endl;
    return 0;
}
