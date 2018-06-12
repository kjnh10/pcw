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


template<class T>
T pow(T x, ll n) {
    T r = 1;
    while (n) {
        if (n & 1) r *= x;
        x *= x;
        n >>= 1;
    }
    return r;
}

template<uint MD>
struct ModInt {
    uint v;
    ModInt() : v{0} {}
    ModInt(ll v) : v{normS(v%MD+MD)} {}
    static uint normS(const uint &x) {return (x<MD)?x:x-MD;};
    static ModInt make(const uint &x) {ModInt m; m.v = x; return m;}
    ModInt operator+(const ModInt &r) const {return make(normS(v+r.v));}
    ModInt operator-(const ModInt &r) const {return make(normS(v+MD-r.v));}
    ModInt operator*(const ModInt &r) const {return make(ull(v)*r.v%MD);}
    ModInt& operator+=(const ModInt &r) {return *this=*this+r;}
    ModInt& operator-=(const ModInt &r) {return *this=*this-r;}
    ModInt& operator*=(const ModInt &r) {return *this=*this*r;}
    static ModInt inv(const ModInt &x) {
        return pow(ModInt(x), MD-2);
    }
};

using Mint = ModInt<TEN(9)+7>;
const int MN = 900900;
Mint fact[MN], iFac[MN], p3[MN];
void first() {
    fact[0] = 1;
    for (int i = 1; i < MN; i++) {
        fact[i] = fact[i-1]*i;
    }
    for (int i = 0; i < MN; i++) {
        iFac[i] = Mint::inv(fact[i]);
    }
    p3[0] = 1;
    for (int i = 1; i < MN; i++) {
        p3[i] = p3[i-1]*3;
    }
}

Mint C(int n, int k) {
    if (n < k || k < 0) return 0;
    return fact[n]*iFac[k]*iFac[n-k];
}

Mint buf[MN];
int main() {
    first();
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k); n--;

    buf[0] = 1;
    for (int i = 1; i <= m+k; i++) {
        buf[i] = buf[i-1]*2;
        if (i-1 >= m) {
            buf[i] -= C(i-1, m);
        }
        if (i-1 >= k) {
            buf[i] -= C(i-1, k);
        }
    }
    Mint ans = 0;
    for (int i = 0; i <= m+k; i++) {
        Mint res = p3[m+k-i];
        res *= C(n+i, n);
        res *= buf[i];
        ans += res;
    }
    printf("%d\n", ans.v);
    return 0;
}