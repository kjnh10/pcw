#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) {return (n==0)?1:10*TEN(n-1);}
template<class T> using V = vector<T>;

int main() {
    int n;
    ll W;
    cin >> n >> W;
    V<ll> w(n), v(n);
    ll cnt[4] = {};
    V<ll> vs[4];
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
        cnt[w[i]-w[0]]++;
        vs[w[i]-w[0]].push_back(v[i]);
    }
    sort(begin(vs[0]), end(vs[0]), greater<ll>());
    sort(begin(vs[1]), end(vs[1]), greater<ll>());
    sort(begin(vs[2]), end(vs[2]), greater<ll>());
    sort(begin(vs[3]), end(vs[3]), greater<ll>());
    ll ans = 0;
    for (int a = 0; a <= cnt[0]; a++) {
        for (int b = 0; b <= cnt[1]; b++) {
            for (int c = 0; c <= cnt[2]; c++) {
                for (int d = 0; d <= cnt[3]; d++) {
                    ll wsm = 0;
                    wsm += a * (w[0] + 0);
                    wsm += b * (w[0] + 1);
                    wsm += c * (w[0] + 2);
                    wsm += d * (w[0] + 3);
                    if (W < wsm) continue;
                    ll vsm = 0;
                    for (int i = 0; i < a; i++) {
                        vsm += vs[0][i];
                    }
                    for (int i = 0; i < b; i++) {
                        vsm += vs[1][i];
                    }
                    for (int i = 0; i < c; i++) {
                        vsm += vs[2][i];
                    }
                    for (int i = 0; i < d; i++) {
                        vsm += vs[3][i];
                    }
                    ans = max(ans, vsm);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
