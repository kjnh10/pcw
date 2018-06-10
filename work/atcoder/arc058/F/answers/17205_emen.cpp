#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

typedef pair<int, int> pii;

const int maxn = 2005;
const int maxk = 10005;
string s[maxn];
bitset<maxk> can[maxn];
pii pos[2][1000051];

int chch[1000];

int TM = 0;
inline bool tl() {
    if (++TM == 10000) {
        TM = 0;
        if (clock() > CLOCKS_PER_SEC * 4.6)
            return true;
    }
    return false;
}

int main() {
    #ifdef LOCAL
    assert(freopen("f.in", "r", stdin));
    #else
    #endif
    cin.tie(0);
    cin.sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    forn (i, n) {
        cin >> s[i];
        for (auto c: s[i])
            ++chch[c];
    }

    int cch = 0;
    for (char c = 'z'; c >= 'a'; --c) {
        cch += (chch[c] > 0);
    }
    if (cch == 1) {
        for (char c = 'a'; c <= 'z'; ++c)
            if (chch[c] > 0) {
                cout << string(k, c) << '\n';
            }
        return 0;
    }

    can[n][0] = 1;
    for (int i = n; i > 0; --i)
        can[i - 1] = can[i] | (can[i] << s[i - 1].length());
    string ans;
    int q = 0, cnt = 0;
    forn (i, n)
        if (can[i + 1][k - sz(s[i])])
            pos[q][cnt++] = {i, 0};
    forn (i, k) {
        char minCh = 'z';
        cnt = min(cnt, 10000);
        forn (ii, cnt) {
            int sid = pos[q][ii].first;
            int spos = pos[q][ii].second;
            minCh = min(minCh, s[sid][spos]);
        }
        ans.push_back(minCh);
        int ncnt = 0;
        int minSt = inf;
        forn (ii, cnt) {
            int sid = pos[q][ii].first;
            int spos = pos[q][ii].second;
            if (s[sid][spos] != minCh)
                continue;
            if (spos + 1 == sz(s[sid]))
                minSt = min(minSt, sid + 1);
            else
                pos[q ^ 1][ncnt++] = {sid, spos + 1};
        }
        for (int j = minSt; j < n; ++j)
            if (k - i - 1 - sz(s[j]) >= 0 && can[j + 1][k - i - 1 - sz(s[j])])
                pos[q ^ 1][ncnt++] = {j, 0};
        q ^= 1;
        cnt = ncnt;
    }
    cout << ans << '\n';
}
