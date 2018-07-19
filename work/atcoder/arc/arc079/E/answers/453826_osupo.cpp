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

//template
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }

ll calc(V<ll> v) {
    ll n = v.size();
    ll ans = 0;
    while (true) {
        ll sm = 0;
        for (ll d: v) {
            sm += d / n;
        }
        if (sm == 0) break;
        ans += sm;
        for (ll &d: v) {
            d = (d % n) + sm - d / n;
        }
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;
    V<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << calc(v) << endl;
    return 0;
}
