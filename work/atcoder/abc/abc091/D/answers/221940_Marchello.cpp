#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
istream &operator>>(istream &in, vector<T> &a) {
    for (auto &item : a) {
        in >> item;
    }
    return in;
}

template<typename T>
ostream &operator<<(ostream &out, vector<T> &a) {
    for (auto &item : a) {
        out << item << " ";
    }
    return out;
}

template<typename T>
ostream &operator<<(ostream &out, vector<vector<T>> &a) {
    for (auto &item : a) {
        out << item << "\n";
    }
    return out;
}

const int MAXN = (int) 1e7;

struct Fenv {
    int n;
    int t[MAXN];

    Fenv(int n) : n(n) { }

    int sum(int r) {
        int res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) res += t[r];
        return res;
    }

    void inc(int i, int d) {
        for (; i < n; i = (i | (i + 1))) t[i] += d;
    }

    int sum(int l, int r) {
        return sum(r - 1) - sum(l - 1);
    }

    void clear() {
        fill_n(t, n, 0);
    }
};

const int INF = (int) 1e9;
const int LOGN = 29;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n], b[n];
    int have[3 * n * LOGN];
    int haveSz = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int msk = 0;
        for (int l = 0; l < LOGN; ++l) {
            msk |= 1 << l;
            have[haveSz++] = a[i] & msk;
        }
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        int msk = 0;
        for (int l = 0; l < LOGN; ++l) {
            msk |= 1 << l;
            have[haveSz++] = b[i] & msk;
        }
    }
    sort(have, have + haveSz);
    haveSz = (int)(unique(have, have + haveSz) - have);
    auto get = [&](int x) {
        return (int) (lower_bound(have, have + haveSz, x) - have);
    };
    int ans = 0;
    Fenv f(haveSz);
    int lsh = 1;
    int msk = 1, ost = 0;
    for (int l = 0; l < LOGN; ++l, lsh <<= 1) {
        msk |= lsh;
        f.clear();
        for (int i = 0; i < n; ++i) {
            f.inc(get(b[i] & msk), 1);
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if ((a[i] >> l) & 1) {
                res += f.sum(get(lsh - (a[i] & ost)) - 1);
                res += f.sum(get(lsh + (lsh - (a[i] & ost))), get(INF));
            } else {
                res += f.sum(get(lsh - (a[i] & ost)),
                             get(lsh + (lsh - (a[i] & ost))));
            }
            res &= 1;
        }
        ans |= res << l;
        ost |= lsh;
    }
    cout << ans << "\n";
    return 0;
}