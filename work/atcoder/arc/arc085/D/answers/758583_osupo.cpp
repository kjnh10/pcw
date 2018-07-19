#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n; ll z, w;
    cin >> n >> z >> w;
    V<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = abs(a[n-1] - w);
    if (n > 1) {
        ans = max(ans, abs(a[n-1] - a[n-2]));
    }
    cout << ans << endl;
    return 0;
}
