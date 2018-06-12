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

ll calc1(int n, V<ll> x, V<ll> y) {
    // pattern 1 [min, ???], [???, max]
    for (int i = 0; i < n; i++) {
        if (x[i] > y[i]) swap(x[i], y[i]);
    }
    sort(begin(x), end(x));
    sort(begin(y), end(y));
    return (x[n-1] - x[0]) * (y[n-1] - y[0]);
}

ll calc2(int n, V<ll> x, V<ll> y) {
    // pattern 2 [min, max], [???, ???]
    using P = array<ll, 2>;
    V<P> v;
    ll mi = TEN(18), ma = -TEN(18);
    multiset<ll> s;
    for (int i = 0; i < n; i++) {
        if (x[i] > y[i]) swap(x[i], y[i]);
        v.push_back(P{x[i], y[i]});
        mi = min(mi, x[i]);
        ma = max(ma, y[i]);
        s.insert(x[i]);
    }
    sort(begin(v), end(v));
    ll ans = (ma - mi) * (*s.rbegin() - *s.begin());
    for (int i = 0; i < n; i++) {
        s.erase(s.find(v[i][0]));
        s.insert(v[i][1]);
        ans = min(ans, (ma - mi) * (*s.rbegin() - *s.begin()));
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    V<ll> x(n), y(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &(x[i]), &(y[i]));
    }
    printf("%lld\n", min(calc1(n, x, y), calc2(n, x, y)));
    return 0;
}
