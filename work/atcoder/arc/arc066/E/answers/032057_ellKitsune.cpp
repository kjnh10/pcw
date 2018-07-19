#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100005];
char s[100005];

int main() {
    scanf("%d", &n);
    forn(i, n) {
        if (i == 0) {
            s[i] = '+';
        } else {
            scanf(" %c", s + i);
        }
        scanf("%d", a + i);
    }
    LL ans = 0;
    forn(i, n) {
        ans += a[i];
    }
    bool ok = true;
    forn(i, n) if (s[i] == '-') {
        ok = false;
        break;
    }
    if (ok) {
        cout << ans << endl;
        return 0;
    }
    LL sum = ans;
    ans *= -1;
    forn(i, n) if (s[i] == '-') {
        LL cur = a[i];
        for (int j = i + 1; j < n; ++j) {
            if (s[j] == '-') {
                break;
            }
            cur += a[j];
        }
        ans = max(ans, sum - 2ll * cur);
        sum -= 2ll * a[i];
    }
    cout << ans << endl;
    return 0;
}
