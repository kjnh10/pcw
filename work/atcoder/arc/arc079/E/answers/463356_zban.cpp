#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll check(vector<ll> a) {
    int n = a.size();

    ll ans = 0;
    while (1) {
        bool f = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= n) {
                f = 1;
                ll k = a[i] / n;
                ans += k;
                a[i] %= n;
                for (int j = 0; j < n; j++) if (i != j) a[j] += k;
            }
        }
        if (!f) break;
    }

    return ans;
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
    //cerr << check(vector<ll>(50, 1e16 + 100)) << endl;

    int n;
    while (cin >> n) {
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        cout << check(a) << endl;
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}