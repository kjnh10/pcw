#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif


    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }

        ll ans = 1e18;
        ll s1 = 0;
        for (int i = 0; i < n - 1; i++) {
            s1 += a[i];
            ans = min(ans, abs(s1 - (sum - s1)));
        }
        cout << ans << endl;
    }


#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}