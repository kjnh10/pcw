#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<LL, LL> PII;

int n, from, to;
LL a[50];
PII d[51][51];

void add(PII &a, PII b) {
    if (b.first > a.first) {
        a = b;
    } else if (b.first == a.first) {
        a.second += b.second;
    }
}

int main() {
    cin >> n >> from >> to;
    forn(i, n) cin >> a[i];
    forn(i, 51) forn(j, 51) {
        d[i][j] = mp(-1, 0);
    }
    d[0][0] = mp(0, 1);
    forn(i, n) forn(j, n) if (d[i][j].first != -1) {
        add(d[i + 1][j], d[i][j]);
        add(d[i + 1][j + 1], mp(d[i][j].first + a[i], d[i][j].second));
    }
    LL num = 0, denom = 1;
    LL cnt = 0;
    for (int i = from; i <= to; ++i) {
        LL nnum = d[n][i].first;
        LL ndenom = i;
        LL ncnt = d[n][i].second;
        if (nnum * denom > num * ndenom) {
            num = nnum;
            denom = ndenom;
            cnt = ncnt;
        } else if (nnum * denom == num * ndenom) {
            cnt += ncnt;
        }
    }
    printf("%.15f\n", (double)num / denom);
    cout << cnt << endl;
    return 0;
}
