#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

template <class Int, Int mod, Int omega=0>
class QuotRing {
    Int n;
public:
    QuotRing(Int n=0): n(n%mod) {}
    inline QuotRing &operator =(const Int rhs) {
        n = rhs % mod;
        return *this;
    }
    inline QuotRing &operator +=(const QuotRing &rhs) {
        (n += rhs.n) %= mod;
        return *this;
    }
    inline QuotRing &operator -=(const QuotRing &rhs) {
        (n += mod - rhs.n%mod) %= mod;
        return *this;
    }
    inline QuotRing &operator *=(const QuotRing &rhs) {
        (n *= rhs.n) %= mod;
        if (n < 0) n += mod;
        return *this;
    }
    inline QuotRing &operator /=(const QuotRing &rhs) {
        return (*this) *= rhs.reciprocal();
    }
    QuotRing &operator ^=(Int rhs) {
        QuotRing tmp(n);
        for (n=1; rhs; rhs>>=1) {
            if (rhs & 1)
                *this *= tmp;
 
            tmp *= tmp;
        }
        return *this;
    }
    inline QuotRing operator +(const QuotRing &rhs) const {
        QuotRing tmp(*this);
        return tmp += rhs;
    }
    inline QuotRing operator -(const QuotRing &rhs) const {
        QuotRing tmp(*this);
        return tmp -= rhs;
    }
    inline QuotRing operator *(const QuotRing &rhs) const {
        QuotRing tmp(*this);
        return tmp *= rhs;
    }
    inline QuotRing operator /(const QuotRing &rhs) const {
        QuotRing tmp(*this);
        return tmp /= rhs;
    }
    inline QuotRing operator ^(const Int rhs) const {
        QuotRing tmp(*this);
        return tmp ^= rhs;
    }
    inline QuotRing reciprocal() const {
        return (*this) ^ (mod-2);
    }
    inline Int to_i() const {
        return n;
    }

    friend istream &operator >>(istream &is, QuotRing &qr) {
        return is >> qr.n;
    }
    friend ostream &operator <<(ostream &os, QuotRing &qr) {
        return os << qr.n;
    }
};

template <class Int, Int mod, Int omega=0>
class ModChooseTable {
    using ModInt=QuotRing<Int, mod, omega>;
    vector<vector<ModInt>> table;
public:
    ModChooseTable(size_t n): table(n, vector<ModInt>(n, 0)) {
        table[0][0] = 1;

        for (size_t i=1; i<n; ++i) {
            table[i][0] = table[i][i] = 1;
            for (size_t j=1; j<i; ++j)
                table[i][j] = table[i-1][j-1] + table[i-1][j];
        }
    }
    ModInt get(size_t n, size_t r) {
        return table[n][r];
    }
};

const int MOD=1e9+7;

int main() {
    int64_t R, C, X, Y, D, L;
    cin >> R >> C >> X >> Y >> D >> L;

    int64_t N=D+L;
    ModChooseTable<int64_t, MOD> ncr(X*Y+1);

    QuotRing<int64_t, MOD> res=ncr.get(N, L);
    res *= R-X+1;
    res *= C-Y+1;

    if (N == X*Y)
        return !(cout << res << '\n');

    QuotRing<int64_t, MOD> tmp=0;
    for (int i=0; i<=2; ++i) {
        if (X < i) continue;
        for (int j=0; j<=2; ++j) {
            if (Y < j) continue;

            QuotRing<int64_t, MOD> cur(1<<((i&1)+(j&1)));
            cur *= ncr.get((X-i)*(Y-j), N);

            if ((i+j) & 1) {
                tmp -= cur;
            } else {
                tmp += cur;
            }
        }
    }

    res *= tmp;
    cout << res << '\n';
    return 0;
}
