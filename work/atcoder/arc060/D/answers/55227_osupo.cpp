#include <iostream>
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
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T = ll> constexpr T TEN(int n) {return (n==0)?1:10*TEN<T>(n-1);}

ll f(ll b, ll n) {
    ll ans = 0;
    while (n) {
        ans += n%b;
        n /= b;
    }
    return ans;
}

int main() {
    ll n, s;
    cin >> n >> s;
    for (ll b = 2; b <= TEN(6); b++) {
        if (f(b, n) == s) {
            cout << b << endl;
            return 0;
        }
    }
    ll ans = TEN(18);
    if (n == s) ans = n+1;
    for (ll u = 1; u <= TEN(6); u++) {
        // u, s-u
        // u * b + (s-u) = n
        // b = (n-s)/u + 1
        ll b = (n-s)/u + 1;
        if (b < 2) continue;
        if (f(b, n) != s) continue;
        ans = min(ans, b);
    }
    if (ans == TEN(18)) ans = -1;
    cout << ans << endl;
    return 0;
}