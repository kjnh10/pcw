#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

template<typename T>
inline void setmax(T& a, T b) {
    if (a < b) a = b;
}

template<typename T>
inline void setmin(T& a, T b) {
    if (a > b) a = b;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int SZ = 26;
const int N = 2e5 + 10;
int nxt[N][SZ];
int dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    vector<int> tmp(SZ, n);
    ford(i, 0, n) {
        forn(j, 0, SZ) nxt[i][j] = tmp[j];
        tmp[s[i] - 'a'] = i;
    }
    dp[n] = 0;
    ford(i, 0, n) {
        dp[i] = INF;
        forn(j, 0, SZ) setmin(dp[i], dp[nxt[i][j]] + 1);
    }
    int opt = 0;
    forn(i, 0, SZ)
        if (dp[tmp[i]] < dp[tmp[opt]]) {
            opt = i;
        }
    cout << char('a' + opt);
    int pos = tmp[opt];
    while (pos < n) {
        forn(j, 0, SZ) {
            if (dp[pos] == 1 + dp[nxt[pos][j]]) {
                cout << char('a' + j);
                pos = nxt[pos][j];
                break;
            }
        }
    }
    cout << '\n';
}
